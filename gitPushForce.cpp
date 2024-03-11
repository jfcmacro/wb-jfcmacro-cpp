#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <git2.h>

namespace fs = std::filesystem;

struct ProgressData {
  ::git_indexer_progress fetch_progress;
  size_t completed_steps;
  size_t total_steps;
  const char *path;
};

static void
printProgress(const ProgressData *pd)
{
  int network_percent = pd->fetch_progress.total_objects > 0 ?
    (100*pd->fetch_progress.received_objects) / pd->fetch_progress.total_objects :
    0;
  int index_percent = pd->fetch_progress.total_objects > 0 ?
    (100*pd->fetch_progress.indexed_objects) / pd->fetch_progress.total_objects :
    0;

  int checkout_percent = pd->total_steps > 0
    ? (int)((100 * pd->completed_steps) / pd->total_steps)
    : 0;
  size_t kbytes = pd->fetch_progress.received_bytes / 1024;

  if (pd->fetch_progress.total_objects &&
      pd->fetch_progress.received_objects == pd->fetch_progress.total_objects) {
    std::cout << "Resolving deltas " // Format: %u/%u\r",
              <<  static_cast<unsigned int>(pd->fetch_progress.indexed_deltas)
              << '/'
              <<  static_cast<unsigned int>(pd->fetch_progress.total_deltas)
              << std::endl;
  } else {
    // printf("net %3d%% (%4" PRIuZ " kb, %5u/%5u)  /  idx %3d%% (%5u/%5u)  /  chk %3d%% (%4" PRIuZ "/%4" PRIuZ")%s\n",
    //        network_percent, kbytes,
    //        pd->fetch_progress.received_objects, pd->fetch_progress.total_objects,
    //        index_percent, pd->fetch_progress.indexed_objects, pd->fetch_progress.total_objects,
    //        checkout_percent,
    //        pd->completed_steps, pd->total_steps,
    //        pd->path);
    std::cout << "net ";
    std::cout.width(3);
    std::cout << network_percent
              << " % ("
              << kbytes
              << " "
              << pd->fetch_progress.received_objects
              << " "
              << pd->fetch_progress.total_objects
              << " "
              << index_percent
              << " kb, (";
    std::cout.width(5);
    std::cout << static_cast<unsigned int>(pd->fetch_progress.indexed_objects)
              << "/";
    std::cout.width(5);
    std::cout << static_cast<unsigned int>(pd->fetch_progress.total_objects)
              << ")  /  chk ";
    std::cout.width(3);
    std::cout << checkout_percent
              << " "
              << pd->completed_steps
              << " "
              << pd->total_steps
              << " "
              << pd->path
              << std::endl;
  }
}

static int
sidebandProgress(const char *str, int len, void *payload) {
  (void)payload; /* unused */

  std::cout << "remote: " << len << " " << str << std::endl;;
  std::cout.flush();
  return 0;
}

static int fetchProgress(const ::git_indexer_progress *stats,
                         void *payload) {
  ProgressData *pd = static_cast<ProgressData*>(payload);
  pd->fetch_progress = *stats;
  printProgress(pd);
  return 0;
}

static void
checkoutProgress(const char* path,
                 size_t cur,
                 size_t tot,
                 void* payload) {
  ProgressData *pd = static_cast<ProgressData*>(payload);
  pd->completed_steps = cur;
  pd->total_steps = tot;
  pd->path = path;
  printProgress(pd);
}

static int
credPassThrough(::git_credential **out,
                const char *url,
                const char *userNameURL,
                unsigned int allowed_types,
                void *payload) {
  return GIT_PASSTHROUGH;
}

static int
credAcquireCb(::git_credential **out,
              const char *url,
              const char *userNameURL,
              unsigned int allowed_types,
              void *payload) {
  std::string userName { userNameURL } ;
  std::string passWord { "" };
  unsigned int credentialTypes[] = { GIT_CREDENTIAL_SSH_KEY,
                                     GIT_CREDENTIAL_USERPASS_PLAINTEXT,
                                     GIT_CREDENTIAL_USERNAME };
  static int nextTypeToTry = -1;

  int status = GIT_ERROR;

  nextTypeToTry++;
  std::cout << "Trying to get a credential"
            << " nextTypetoTry: " << nextTypeToTry
            << " sizeof(credentialTypes) "
            << (sizeof(credentialTypes) / sizeof(unsigned int))
            << " currentType: " << credentialTypes[nextTypeToTry]
            << std::endl;
  if (nextTypeToTry < sizeof(credentialTypes) / sizeof(int)) {
    switch (credentialTypes[nextTypeToTry]) {
    case GIT_CREDENTIAL_SSH_KEY:
      if (allowed_types & credentialTypes[nextTypeToTry]) {
        fs::path privKey { "/home/juancardona/.ssh/id_ed25519" };
        fs::path pubKey  { privKey };
        pubKey.replace_extension(".pub");

        std::cout << "Url: " << url << std::endl
                  << "Username: " << userName << std::endl
                  << "Private Key: " << privKey << std::endl
                  << "Public Key: " << pubKey << std::endl
                  << "Password: " << passWord << std::endl;
        status = ::git_credential_ssh_key_new(out,
                                              userName.c_str(),
                                              pubKey.c_str(),
                                              privKey.c_str(),
                                              passWord.c_str());
      }
      break;
    case GIT_CREDENTIAL_USERPASS_PLAINTEXT:
      if (allowed_types & credentialTypes[nextTypeToTry]) {
        std::cout << "Password: ";
        std::cout.flush();
        std::cin >> passWord;
        status = ::git_credential_userpass_plaintext_new(out,
                                                         userName.c_str(),
                                                         passWord.c_str());
      }
      break;
    case GIT_CREDENTIAL_USERNAME:
      if (allowed_types & GIT_CREDENTIAL_USERNAME) {
        status = ::git_credential_username_new(out,
                                               userName.c_str());
      }
      break;
    default:
      status = GIT_ERROR;
      break;
    }
  }
  else {
    status = GIT_ERROR;
  }

  std::cout << "Status: " << status << std::endl;

  return status;
}

int
main(int argc, char *argv[]) {

  ::git_libgit2_init();
  ::git_repository *repo = nullptr;

  if (::git_repository_init(&repo, ".", false) < 0) {
    std::cerr << "Cannot be intialized" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  ::git_index *idx = nullptr;

  if (::git_repository_index(&idx, repo) < GIT_OK) {
    std::cerr << "Repo Index cannot be obtained" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  ::git_oid oid;
  ::git_revwalk *walker = nullptr;
  ::git_commit *commit = nullptr;

  if (::git_revwalk_new(&walker, repo) < GIT_OK) {
    std::cerr << "Couldn't create revision walker" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  if (::git_revwalk_push_head(walker) < GIT_OK) {
    std::cerr << "Couldn't find revision HEAD" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  ::git_commit *firstCommit = nullptr;
  for (; !::git_revwalk_next(&oid, walker); ::git_commit_free(commit)) {

    if (::git_commit_lookup(&commit, repo, &oid)) {
      std::cerr << "Failed to look up commit" << std::endl;
      ::git_libgit2_shutdown();
      ::exit(EXIT_FAILURE);
    }

    if (firstCommit)
      ::git_commit_free(firstCommit);

    ::git_commit_dup(&firstCommit, commit);
  }

  // Here start push force
  ::git_remote* remote = nullptr;

  if (::git_remote_lookup(&remote, repo, "origin") < GIT_OK) {
      std::cerr << "Unable to lookup remote" << std::endl;
      ::git_libgit2_shutdown();
      ::exit(EXIT_FAILURE);
  }

  ::git_push_options d_git_push_options;

  if (::git_push_options_init(&d_git_push_options,
                              GIT_PUSH_OPTIONS_VERSION) < GIT_OK) {
      std::cerr << "Error initializing push" << std::endl;
      ::git_libgit2_shutdown();
      ::exit(EXIT_FAILURE);
  }

  ProgressData pd = { {0} };

  d_git_push_options.callbacks.sideband_progress = sidebandProgress;
  d_git_push_options.callbacks.transfer_progress = &fetchProgress;
  d_git_push_options.callbacks.credentials = credAcquireCb;
  d_git_push_options.callbacks.payload = &pd;

  const char* REFSPEC = "+refs/heads/main:refs/heads/main";
  char* ref_spec = new char[::strlen(REFSPEC) + 1];
  ::strcpy(ref_spec, REFSPEC);
  const git_strarray refspecs = {
    &ref_spec,
    1
  };

  if (::git_remote_push(remote,
                        &refspecs,
                        &d_git_push_options) < GIT_OK) {
      std::cerr << "Error pushing" << std::endl;
      ::git_libgit2_shutdown();
      ::exit(EXIT_FAILURE);
  }

  ::git_libgit2_shutdown();
  ::exit(EXIT_SUCCESS);
}

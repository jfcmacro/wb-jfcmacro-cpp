#include <iostream>
#include <string>
#include <cstdlib>
#include <git2.h>

int
main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <message> " << std::endl;
    ::exit(EXIT_FAILURE);
  }

  const char *message = argv[1];
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

  // Here start commit amend

  ::git_config *config_default;

  if (::git_config_open_default(&config_default) < GIT_OK) {
    std::cerr << "Cannot open default configuration" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  ::git_config_entry *entry;

  if (::git_config_get_entry(&entry,
                             config_default,
                             "user.name") < GIT_OK) {
    std::cerr << "Cannot find user name at default config" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  std::string userName { entry->value };
  ::git_config_entry_free(entry);

  if (::git_config_get_entry(&entry,
                             config_default,
                             "user.email") < GIT_OK) {
    std::cerr << "Cannot find user email at default config" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  std::string userEmail { entry->value };
  ::git_config_entry_free(entry);

  ::git_signature *signature = nullptr;

  if (::git_signature_now(&signature,
                          userName.c_str(),
                          userEmail.c_str()) < GIT_OK) {
    std::cerr << "Cannot create user signature" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  // ::git_reference *ref = nullptr;
  // ::git_object  *parent = nullptr;

  // if (::git_revparse_ext(&parent,
  //                        &ref,
  //                        repo,
  //                        "HEAD") != GIT_ENOTFOUND) {
  //   std::cerr << "Error getting parent and reference" << std::endl;
  //   ::git_libgit2_shutdown();
  //   ::exit(EXIT_FAILURE);
  // }

  ::git_index *index = nullptr;

  if (::git_repository_index(&index,
                             repo) < GIT_OK) {
    std::cerr << "Could not open repository index" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  ::git_oid tree_oid;

  if (::git_index_write_tree(&tree_oid,
                             index) < GIT_OK) {
    std::cerr << "Could not write tree" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  if (::git_index_write(index) < GIT_OK) {
    std::cerr << "Could not write index" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  ::git_tree *tree = nullptr;

  if (::git_tree_lookup(&tree,
                        repo,
                        &tree_oid) < GIT_OK) {
    std::cerr << "Could get tree index" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  ::git_oid new_commit_id;

  if (::git_commit_amend(&new_commit_id,
                         firstCommit,
                         "HEAD",
                         signature,
                         signature,
                         "UTF-8",
                         message,
                         tree) < GIT_OK) {
    std::cerr << "Couldn't amend last commit" << std::endl;
    ::git_libgit2_shutdown();
    ::exit(EXIT_FAILURE);
  }

  ::git_libgit2_shutdown();
  ::exit(EXIT_SUCCESS);
}

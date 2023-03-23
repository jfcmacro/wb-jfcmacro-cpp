#include <iostream>
#include <cstdlib>
#include <git2.h>

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

  // Here we start the reset force
  if (firstCommit) { // No empty
    ::git_checkout_options gco = GIT_CHECKOUT_OPTIONS_INIT; // = git_checkout_options_init;
    if (::git_reset(repo,
                    // static_cast<git_object*>(firstCommit),
                    (git_object*) firstCommit,
                    GIT_RESET_HARD,
                    &gco) < GIT_OK) {
      std::cerr << "Hard Rest failed" << std::endl;
      ::git_libgit2_shutdown();
      ::exit(EXIT_FAILURE);
    }
  }

  ::git_libgit2_shutdown();
  ::exit(EXIT_SUCCESS);
}

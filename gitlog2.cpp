#include <iostream>
// #include <fstream>
// #include <sstream>
#include <cstdlib>
// #include <iomanip>
// #include <string>
// #include <cstring>
// #include <filesystem>
// #include <getopt.h>
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

  std::cout << "Try to browse the commits" << std::endl;
  for (; !::git_revwalk_next(&oid, walker); ::git_commit_free(commit)) {

    if (::git_commit_lookup(&commit, repo, &oid)) {
      std::cerr << "Failed to look up commit" << std::endl;
      ::git_libgit2_shutdown();
      ::exit(EXIT_FAILURE);
    }

    char buf[41];

    ::git_oid_tostr(buf, sizeof(buf), ::git_commit_id(commit));
    std::cout << "Commit: " << buf << std::endl;
  }

  ::git_libgit2_shutdown();
  ::exit(EXIT_SUCCESS);
}

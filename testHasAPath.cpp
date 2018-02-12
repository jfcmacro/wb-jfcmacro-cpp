#include <iostream>
#include <cstring>
#include <string>
#include <libgen.h>

bool
hasAPath(const std::string& cmd) {
  char *path = new char[cmd.size() + 1];
  ::strcpy(path, cmd.c_str());
  char *start_path = ::dirname(path);
  std::cout << start_path << std::endl;
  return ::strcmp(start_path, ".") != 0;
}

int
main(void) {

  std::string emacs("/usr/bin/emacs");
  std::string relative(".././c++/testHasAPath");
  std::string local("./testHasAPath");
  std:: string vim("vim");

  std::cout << hasAPath(emacs) << std::endl;
  std::cout << hasAPath(relative) << std::endl;
  std::cout << hasAPath(local) << std::endl;
  std::cout << hasAPath(vim) << std::endl;

  return 0;
}

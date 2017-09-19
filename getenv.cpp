#include <iostream>
#include <libgen.h>

int
main(int argc, char *argv[], char *env[]) {
  for (int i = 0; env[i]; ++i) {
    std::cout << "env[" << i << "]=" << env[i] << std::endl;
  }

  for (int i = 0; i < argc; ++i) {
    std::cout << "argv[" << i << "]=" << argv[i] << std::endl;
  }

  char *processPath = ::getenv("_");

  std::cout << "env[_]=" << processPath << std::endl;

  char *execPath = ::dirname(processPath);

  std::cout << "execpath=" << execPath << std::endl;
  return 0;
}

#include <iostream>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

void diffDirAction(fs::path srcDir, fs::path dstDir, bool isRoot);

int
main(int argc, char *argv[]) {
  fs::path srcDir { "/home/jfcmacro/Workbench/command-generic-story/target/repositories/commandlambdastream" };
  fs::path dstDir { "/home/jfcmacro/Workbench/command-generic-story/target/repository/" };

  diffDirAction(srcDir, dstDir, true);

  return EXIT_SUCCESS;
}

  

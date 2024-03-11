#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cstdlib>

namespace fs = std::filesystem;

static void usage(const char* progname) {
  fs::path prog { progname };

  std::cerr << "usage: " << prog.filename() << " <dir-to-iterate>" << std::endl;

  ::exit(EXIT_FAILURE);
}

int
main(int argc, char *argv[]) {
  if (argc != 2) usage(argv[0]);

  const fs::path dir { argv[1] };

  for (auto const& dir_entry : fs::directory_iterator { dir }) {
    std::cout << dir_entry.path() << std::endl;
  }

  return EXIT_SUCCESS;
}

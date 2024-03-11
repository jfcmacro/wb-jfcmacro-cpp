#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <string>
#include <utility>
#include <list>
#include <cstdlib>

namespace fs = std::filesystem;

static void usage(const char* progname);
std::list<std::pair<fs::path,fs::path>>& getListSSHKeys();

int
main(int argc, char *argv[]) {
  if (argc != 1) usage(argv[0]);

  std::list<std::pair<fs::path,fs::path>>& keys = getListSSHKeys();

  for (std::pair<fs::path, fs::path> p : keys) {
    std::cout << "Private: " << p.first << " Public: " << p.second << std::endl;
  }

  return EXIT_SUCCESS;
}

static void usage(const char* progname) {
  fs::path prog { progname };

  std::cerr << "usage: " << prog.filename() << std::endl;

  ::exit(EXIT_FAILURE);
}

std::list<std::pair<fs::path,fs::path>>& getListSSHKeys() {
 fs::path sshDir { ::getenv("HOME") };
 sshDir /= ".ssh";

 std::list<std::pair<fs::path,fs::path>> *keys =
   new std::list<std::pair<fs::path,fs::path>>();

  for (auto const& dir_entry : fs::directory_iterator { sshDir }) {
    if (dir_entry.path().extension() == ".pub") {
      fs::path privKey { dir_entry.path() };
      privKey.replace_extension("");
      std::pair<fs::path, fs::path> p { privKey, dir_entry.path() };
      keys->push_back(p);
    }
  }

  return *keys;
}

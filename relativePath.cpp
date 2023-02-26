#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <iterator>

namespace fs = std::filesystem;

void getRelativeFrom(const fs::path& firstPath,
                     const fs::path& secondPath,
                     fs::path& result) {

  int distFirstPath = std::distance(firstPath.begin(),
                                    firstPath.end());
  int distSecondPath = std::distance(secondPath.begin(),
                                     secondPath.end());

  const fs::path *longPath = &firstPath;
  const fs::path *shortPath = &secondPath;

  if (distFirstPath <= distSecondPath) {
    longPath = &secondPath;
    shortPath = &firstPath;
  }

  fs::path::iterator itl = longPath->begin();
  for (fs::path::iterator its = shortPath->begin();
       itl != longPath->end() and its != shortPath->end() and *itl == *its;
       ++itl, ++its);

  result.clear();
  for (; itl != longPath->end(); ++itl)
    result /= *itl;
}

int
main(int argc, char *argv[]) {
  fs::path longPath { "/home/juancardona/Workbench/wb-jfcmacro-c++/relativePath.cpp" };
  fs::path shortPath { "/home/juancardona/Workbench/" };

  // // std::cout << "Long: " << longPath
  // //           << " distance: " << std::distance(longPath.begin(), longPath.end())
  // //           << std::endl
  // //           << " short: " << shortPath
  // //           << " distance: " << std::distance(shortPath.begin(), shortPath.end())
  // //           << std::endl;
  // fs::path::iterator itl = longPath.begin();
  // for (fs::path::iterator its = shortPath.begin();
  //      itl != longPath.end() and its != shortPath.end() and *itl == *its;
  //      ++itl, ++its);

  // fs::path rest;
  // for (; itl != longPath.end(); ++itl)
  //   rest /= *itl;

  fs::path result;
  getRelativeFrom(longPath, shortPath, result);
  std::cout << "Path: " << result << std::endl;

  getRelativeFrom(shortPath, longPath, result);
  std::cout << "Path: " << result << std::endl;

  // fs::current_path(shortPath);

  // std::cout << "Relative: " << rest << std::endl;

  // if (fs::exists(rest))
  //   std::cout << "It exists";
  // else
  //   std::cout << "It doesn't exists";
  // std::cout << std::endl;
  return EXIT_SUCCESS;
}

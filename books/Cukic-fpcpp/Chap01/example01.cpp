#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

std::vector<int>
count_lines_in_files(const std::vector<std::string>& files) {

  std::vector<int> results;
  char c = 0;

  for (const auto& file : files) {
    int line_count = 0;

    std::ifstream in(file); // , std::ios_base::in);

    while (in.get(c))
      if (c == '\n')
	line_count++;

    results.push_back(line_count);
  }

  return results;
}


int
main(int argc, char *argv[]) {

  std::vector<std::string> files;

  for (int i = 1; i < argc; i++) {
    std::string file(argv[i]);
    files.push_back(file);
  }

  const std::vector<int>& result = count_lines_in_files(files);

  for (const auto& i : result) {
    std::cout << i << std::endl;
  }

  return EXIT_SUCCESS;
}

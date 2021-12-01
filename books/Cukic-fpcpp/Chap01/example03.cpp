#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

int count_lines(const std::string& filename) {
  std::ifstream in(filename);

  return std::count(std::istreambuf_iterator<char>(in),
		    std::istreambuf_iterator<char>(),
		    '\n');
}

std::vector<int>
count_lines_in_files(const std::vector<std::string>& files) {

  std::vector<int> results(files.size());

  std::transform(files.cbegin(), files.cend(),
		 results.begin(), count_lines);

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

  for (const auto& i : result)
    std::cout << i << std::endl;

  return EXIT_SUCCESS;
}

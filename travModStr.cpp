#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

std::string transTex2HTMLEntity(const std::string& input) {
  std::ostringstream oss;

  for (int i = 0; i < input.size(); i++) {
    switch (input[i]) {
    case '<' : oss << "&lt;"; break;
    case '>' : oss << "&gt;"; break;
    case '&' : oss << "&amp;"; break;
    case '"' : oss << "&quot;"; break;
    case '\'' : oss << "&apos;"; break;
    default : oss << input[i]; break;
    }
  }

  return oss.str();
}

int
main(int argc, char**argv) {

  std::string input { "This `Map<T,U>` && \"Document\" 'More document'" };

  std::cout << "Input: " << input << std::endl;
  std::cout << "Output: " << transTex2HTMLEntity(input) << std::endl;

  return EXIT_SUCCESS;
}

#include <iostream>
#include <regex>
#include <cstdlib>
#include <tuple>
#include <string>

// std::tuple<std::string,std::string>
void
divLink(std::string& str) {
  std::regex re { "\\[.*\\[\\(.*\\)" };
  std::cmatch cm;
  std::regex_match("[Esto es un enlace](prueba)", cm, re);
  std::cout << cm[0].first << " " << cm[1] << std::endl;
}

int
main(int argc, char *argv[]) {
  std::string str { "[Esto es un enlace](prueba)" };

  divLink(str);

  return EXIT_SUCCESS;
}

#include <iostream>
#include <cstdlib>
#include <string>

int convertir(std::string& str);

int
main(int argc, char *argv[]) {

  std::string inStr;

  std::cin >> inStr;

  std::cout << inStr << " into " << convertir(inStr) << std::endl;

  return EXIT_SUCCESS;
}

int
convertir(std::string& str) {
  int value = 0;
  for(std::string::iterator it = str.begin();
      it != str.end();
      it++) {
    value *= 10;
    value += *it - '0';
  }
  return value;
}

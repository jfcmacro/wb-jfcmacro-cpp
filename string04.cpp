#include <iostream>
#include <string>
#include <cstdlib>

int
main(void) {
  std::string str {"Hola mundo"};

  std::string sub = str.substr(0,4);

  std::cout << sub << std::endl;

  sub = str.substr(0,std::string::npos);

  std::cout << sub << std::endl;

  sub = str.substr(2,6);

  std::cout << sub << std::endl;

  return EXIT_SUCCESS;
}

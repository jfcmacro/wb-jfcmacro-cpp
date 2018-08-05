#include <iostream>
#include <string>
#include <cstdlib>

int
main(void) {
  
  std::string str;

  std::getline(std::cin, str);

  std::cout << str << std::endl;
  
  return EXIT_SUCCESS;
}

#include <iostream>
#include <string>
#include <cstdlib>

int
main(void) {

  char cSep;

  std::cin >> cSep;
  
  int nFields = 0;
  std::string str;
  
  while (std::getline(std::cin, str)) nFields++;

  std::cout << nFields << std::endl;
  
  return EXIT_SUCCESS;
}

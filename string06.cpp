#include <iostream>
#include <string>
#include <cstdlib>

int
main(void) {
  
  std::string first;

  std::cin >> first;

  std::string str;

  while (std::cin >> str) {
    
    if (first == str) {
      std::cout << "==" << std::endl;
    }
    else if (first < str) {
      std::cout << "<" << std::endl;
    }
    else {
      std::cout << ">" << std::endl;
    }
  }
  
  return EXIT_SUCCESS;
}

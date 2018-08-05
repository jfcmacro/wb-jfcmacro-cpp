#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

int
main(void) {
  
  std::string input;
  while (std::getline(std::cin, input)) {
  
    std::istringstream iss(input);
  
    std::string strdouble;
    double valueLine = 0.0;
    
    while (iss >> strdouble)
      valueLine += stod(strdouble);

    std::cout << valueLine << std::endl;
  }

  return EXIT_SUCCESS;
}

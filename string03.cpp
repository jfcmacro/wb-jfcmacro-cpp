#include <iostream>
#include <string>
#include <cstdlib>

int
main(void) {
  std::string str {"Hola mundo"};

  std::string::size_type pos = str.find("mu");

  if (pos != std::string::npos) std::cout << "pos: " << pos << std::endl;
  
  pos = str.find("no");

  if (pos != std::string::npos) std::cout << "pos: " << pos << std::endl;

  return EXIT_SUCCESS;
}

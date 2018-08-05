#include <iostream>
#include <string>
#include <cstdlib>

int
main(void) {
  // std::string hola = "Hola mundo";
  std::string hola {"Hola mundo"};
  
  for (int i = 0; i < hola.size(); ++i)
    std::cout << hola[i] << std::endl;

  return EXIT_SUCCESS;
}

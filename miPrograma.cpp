#include "funciones.h"
#include <iostream>
#include <cstdlib>

int
main(void) {

  int a, b, c;

  std::cin >> a >> b;

  c = mayorDeDos(a,b);

  std::cout << c << std::endl;
                    
  std::cin >> a >> b;
  
  c = mayorDeDos(c,mayorDeDos(a,b));

  std::cout << c << std::endl;

  return EXIT_SUCCESS;
}

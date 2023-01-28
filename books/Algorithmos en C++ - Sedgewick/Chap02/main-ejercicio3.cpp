#include <iostream>
#include <cstdlib>
#include "fraccion.h"

int
main(void) {
  int de;
  int nu;
  
  while (true) {
    std::cin >> de;
    if (!std::cin) break;
    std::cin >> nu;
    if (!std::cin) break;
    Fraccion fraccion(de,nu);
    
    std::cout << fraccion.obtEntera()
	      << "("
      << fraccion.obtNumerador()
	      << "/"
	      << fraccion.obDenominador()
	      << ")"
	      << std::endl;
  }

  return EXIT_SUCCESS;
}

#include <iostream>
#include <cstdlib>
#include "euclides.h"

class Fraccion {
private:
  int entera;
  int numerador;
  int denominador;
public:
  Fraccion(int numerador,
	   int denominador) : numerador(numerador),
			     denominador(denominador) {
    int mcdf = mcd(numerador, denominador);
    this->numerador = this->numerador / mcdf;
    this->denominador = this->denominador / mcdf;
    this->entera = this->numerador / this->denominador;
    this->numerador = this->numerador % this->denominador;
  }
  Fraccion(int entera,
	   int numerador,
	   int denominador) : Fraccion(entera * denominador + numerador, denominador) {
  }
  int obtEntera() const {
    return entera;
  }
  int obtNumerador() const {
    return numerador;
  }
  int obDenominador() const {
    return denominador;
  }
};

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

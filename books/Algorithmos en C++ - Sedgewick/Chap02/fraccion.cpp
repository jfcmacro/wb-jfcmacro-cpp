#include "fraccion.h"
#include "euclides.h"

Fraccion::Fraccion(int numerador,
		   int denominador) : numerador(numerador),
				      denominador(denominador) {
  int mcdf = mcd(numerador, denominador);
  this->numerador = this->numerador / mcdf;
  this->denominador = this->denominador / mcdf;
  this->entera = this->numerador / this->denominador;
  this->numerador = this->numerador % this->denominador;
}

Fraccion::Fraccion(int entera,
		   int numerador,
		   int denominador) : Fraccion(entera * denominador + numerador, denominador) { }
int Fraccion::obtEntera() const {
    return entera;
}

int Fraccion::obtNumerador() const {
    return numerador;
}

int Fraccion::obDenominador() const {
    return denominador;
}

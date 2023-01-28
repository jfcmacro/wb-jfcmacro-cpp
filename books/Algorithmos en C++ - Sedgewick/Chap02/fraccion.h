#pragma once

class Fraccion {
private:
  int entera;
  int numerador;
  int denominador;
public:
  Fraccion(int numerador,
	   int denominador);
  Fraccion(int entera,
	   int numerador,
	   int denominador);
  int obtEntera() const;
  int obtNumerador() const;
  int obDenominador() const;
};

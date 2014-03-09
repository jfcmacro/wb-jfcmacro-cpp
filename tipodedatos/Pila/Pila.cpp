#include <stdio.h>
#include "Pila.h"

struct Elemento {
  int valor;
  PElemento sig;

  Elemento(int valor) {
    this->valor = valor;
    this->sig = NULL;
  }

  Elemento(int valor, PElemento sig) {
    this->valor = valor;
    this->sig = sig;
  }

  ~Elemento() {
    this->valor = 0;
    this->sig = NULL;
  }
};

Pila::Pila() {
  cabeza = NULL;
  nElementos = 0;
}

int
Pila::push(int valor) {
  PElemento pE = new Elemento(valor, cabeza);
  if (pE == NULL)
    return ENOMEMORY;

  cabeza = pE;
  nElementos++;
  return ENOERROR;
}

int
Pila::pop(int *valor) {
  PElemento pE = cabeza;

  if (pE == NULL)
    return EUNDERFLOW;

  *valor = pE->valor;
  cabeza = cabeza->sig;
  delete pE; 
  return ENOERROR;
}  

int
Pila::tamano() const {
  return nElementos;
}

Pila::~Pila() {

  PElemento pE = cabeza;

  while (pE) {
    PElemento pAnt = pE;
    pE = pE->sig;
    delete pAnt;
  }
}

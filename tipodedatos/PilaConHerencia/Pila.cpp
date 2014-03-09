#include "Pila.h"

using namespace std;

Pila::Pila() {
  cabeza = NULL;
  nElementos = 0;
}

void
Pila::push(Elemento* valor) {
  valor->establecerSiguiente(cabeza);
  cabeza = valor;
  nElementos++;
}

Elemento*
Pila::pop() {
  PElemento pE = cabeza;

  if (pE == NULL)
    return NULL;

  Elemento *valor = cabeza;
  cabeza = cabeza->obtenerSiguiente();
  valor->establecerSiguiente(NULL);
  nElementos--;
  return valor;
}  

int
Pila::totalElementos() const {
  return nElementos;
}

Pila::~Pila() {

  PElemento pE = cabeza;

  while (pE) {
    PElemento pAnt = pE;
    pE = pE->obtenerSiguiente();
    delete pAnt;
  }
}



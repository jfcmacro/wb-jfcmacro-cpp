#include "Elemento.h"

Elemento::Elemento(Elemento* sig) {
  this->sig = sig;
}

Elemento::Elemento() : sig(NULL) { 
}

void
Elemento::establecerSiguiente(Elemento *sig) {
  this->sig = sig;
}

Elemento*
Elemento::obtenerSiguiente() {
  return sig;
}


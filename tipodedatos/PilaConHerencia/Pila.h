#ifndef PILA_H
#define PILA_H "pila_h"

#include "Elemento.h"

class Pila {
  Elemento* cabeza;
  int nElementos;
 public:
  Pila();
  ~Pila();
  void push(Elemento *e);
  Elemento* pop();
  int totalElementos() const;
};
#endif

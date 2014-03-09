#include <iostream>
#include "Pila.h"

int
main(int argc, char* argv[]) {

  Pila pila;

  pila.push(10);
  pila.push(40);
  pila.push(55);

  int valor;

  while (pila.pop(&valor) == ENOERROR) {
    cout << "Valor: " << valor << endl;
  }

  return 0;
}

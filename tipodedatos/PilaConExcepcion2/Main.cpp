#include  "Pila.h"

int
main(int argc, char* argv[]) {

  Pila pila;

  float f1 = 10.0, f2 = 43.3, f3 = 45.3;

  try {
	pila.push((void*) &f1);
	pila.push((void*) &f2);
	pila.push((void*) &f3);
  } 
  catch (NoMemoryException& nme) {
	  cerr << nme << endl;
	  return 1;
  }

  float *valor;

  while ((valor = (float *) pila.pop()) != NULL) {
    cout << "Valor: " << *valor << endl;
  }

  return 0;
}

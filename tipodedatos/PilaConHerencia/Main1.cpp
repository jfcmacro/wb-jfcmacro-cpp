#include <iostream>

#ifdef WINDOWS
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "Pila.h"
#include "ElementoEntero.h"

using namespace std;

int
main(int argc, char *argv[]) {

  Pila p;

  ElementoEntero *ee;

  // Lee 10 enteros
  for (int i = 0; i < 10; i++) {
    int valor;
    cin >> valor;
    ee = new ElementoEntero(valor);
    p.push((Elemento*) ee);
  } 

  Elemento *pe;

  while ((pe = (Elemento *) p.pop()) != NULL) {
    Elemento &pe1 = *pe;
    pe = (Elemento *) p.pop();

    if (pe == NULL)  {
      cerr << "Error: no hay un par de elementos en la pila" << endl;
#ifdef WINDOWS
      ::ExitProcess(1);
#else
      ::exit(1);
#endif
    }

    Elemento &pe2 = *pe;
    
    if (pe1 > pe2) {
      cout << "El valor " << pe1;
      cout << " es mayor que ";
      cout << pe2;
      cout << endl;
    }
    else {
      cout << "El valor ";
      cout << pe1;
      cout << " no es mayor que ";
      cout << pe2;
      cout << endl; 
    }     
  }
}

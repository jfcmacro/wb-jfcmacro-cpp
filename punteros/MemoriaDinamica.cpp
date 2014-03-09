// MemoriaDinamica.cpp
#include <iostream>

using namespace std;

int
main() {
  
  int *x;
  
  // Solicita memoria dinamica a través del
  // operador new
  x = new int;

  // Manipula el contenido de dicha direccion a 
  // traves del operador de dereferencia

  *x = 10;

  cout << "El valor de x es: " << *x  // Obtiene el contenido
       << " y su direccion:  " << x
       << endl;

  // Borra la memoria dinamica
  delete x;

  return 0;
}
  

// PunteroAPuntero.cpp
#include <iostream>

using namespace std;

int
main()
{
  // Declara un puntero a un entero
  int *p = new int;
  // Declara un puntero a un puntero a un entero
  int **pAp = &p;

  // Asigna al contenido que apunta a p
  *p = 10;

  cout << "El contenido de p es: " << *p 
       << " la direccion de p es: " << p 
       << endl;

  cout << "El contenido de la direccion que contiene pAp: " << **pAp
       << " el contenido de pAp es: " << *pAp
       << " la direccion de pAp es: " << pAp
       << endl;

  return 0;
}
    

#include <iostream>
#include <string>

using namespace std;

class FuncionRFuncion {

public:
  static void* funcion(void *argumento) {
    string *x = (string *) argumento;
    cout << *x << endl;
    return (void *) NULL;
  }

  void* (*retonarFuncion())(void *) {
    return funcion;
  }
  
};

int
main() {

  void* (*f)(void *);
  string x = "Hola Mundo";

  FuncionRFuncion frf;

  f = frf.retonarFuncion();

  f((void *) &x);
  return 0;
}

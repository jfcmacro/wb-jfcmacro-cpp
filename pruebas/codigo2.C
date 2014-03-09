#include <iostream>

int
main() {

  extern int variable;
  int funcion(int);

  variable = 10;

  variable = funcion(variable);
  variable = funcion(variable);

  cout << "Variable " << variable << endl;

}

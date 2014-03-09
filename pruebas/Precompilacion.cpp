/* Precompilacion.cpp */
#include <iostream>

#define VALOR_MAX   34000
#define VALOR_MIN   30000

using namespace std;

int
main(int argc, char *argv[]) {
  
  int valor;

  cout << "Entre un valor: " ;
  cin >> valor;

  if (cin.fail()) {
    cerr << "El programa fallo" << endl;
    return 1;
  }
  else if (valor < VALOR_MAX || valor > VALOR_MIN) {
    cout << "El valor que entro esta por fuera del valor máximo" << endl;
  }

  return 0;
}

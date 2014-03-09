//Main.C

#include <iostream>
#include "Generador.h"

int
main(int argc, char* argv[]) {

  Generador g;
  int pos;

  while (cin) {
    cin >> g;
    if (!g.verificar(pos)) 
      cerr << "Problemas en " << pos << endl;
    cout << g << endl;
  }
}

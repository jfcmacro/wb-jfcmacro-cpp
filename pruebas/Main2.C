
//Main.C

#include <iostream>
#include "Generador.h"

int
main(int argc, char* argv[]) {

  Generador g;

  while (cin) {
    cin >> g;
    g.incrementar();
    cout << g << endl;
  }
}

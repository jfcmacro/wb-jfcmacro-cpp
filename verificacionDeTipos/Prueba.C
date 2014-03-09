// verificacionDeTipos
#include <iostream>

using namespace std;

struct Algo1 {
  int valor1;
  int valor2;
};

struct Algo2 {
  int valor1;
  int valor2;
};

void
imprimir(Algo1* algo) {
  cout << "Valor1: " << algo->valor1 
       << " Valor2: " << algo->valor2 << endl;
}

int 
main() {
  
  Algo2 algo;
  algo.valor1 = 10;
  algo.valor2 = 20;
  
  imprimir((Algo1*) &algo);

  return 0;
}

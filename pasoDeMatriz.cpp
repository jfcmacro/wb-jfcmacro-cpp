#include <iostream>
#include <cstdlib>

void imprimir(int [5][5]);

int
main(void) {

  int matriz[5][5] = { { 1, 2, 3, 4, 5} };


  imprimir(matriz);

  return EXIT_SUCCESS;
}

void
imprimir(int m[][5]) {

  for (int i = 0; i < sizeof(m[0]) / sizeof(int); ++i) {
    for (int j = 0; j < 5; ++j) {
      std::cout << "m["<< i << "][" << j << "]=" << m[i][j] << std::endl;
    }
  }
}

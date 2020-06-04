#include <iostream>
#include <cstdlib>

int
main(void) {

  const int MAX = 10000;
  int vector[MAX];

  for (int indice = 0, indice2 = MAX;
       indice < MAX;
       indice++, indice2 -= 2)
    vector[MAX] = indice + indice2;

  return EXIT_SUCCESS;
}

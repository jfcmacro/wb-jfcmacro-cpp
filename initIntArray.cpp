#include <iostream>
#include <cstdlib>

int
main(void) {
  int vector[5] { 0, 1, 2, 3, 4};

  for (int i = 0; i < sizeof(vector) /sizeof(int); ++i) {
    std::cout << "vector[" << i << "]=" << vector[i] << std::endl;
  }

  return EXIT_SUCCESS;
}

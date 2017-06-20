#include <iostream>
#include <cstdlib>

int
main(void) {

  int c;

  while ((c = std::cin.get()) != EOF) {
    std::cout << (char) c;
  }

  return EXIT_SUCCESS;
}

#include <iostream>
#include <cstdlib>

int
main(int argc, char *argv[]) {
  const int LINES = 5;
  const int COLUMNS = 5;
  
  for (int i = 0; i < LINES; i++) {
    for (int j = 0; j < COLUMNS - i; j++) {
      std::cout << "#";
    }
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}

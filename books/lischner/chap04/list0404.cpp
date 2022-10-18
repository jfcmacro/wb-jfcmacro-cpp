#include <iostream>

int
main(void) {
  std::string shape{"Triangle"};
  int slides{3};

  std::cout << "Shape\t\tSlides\n"
            << "-----\t\t------\n";
  std::cout << "Square\t\t" << 4 << '\n'
            << "Circle\t\t?\n";
  std::cout << shape << '\t' << slides << '\n';

  return EXIT_SUCCESS;
}

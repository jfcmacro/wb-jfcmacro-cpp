#include <iostream>
#include <limits>

int
main(void) {
  std::cout << "bits per bool: "
            << std::numeric_limits<bool>::digits
            << std::endl;
  std::cout << "bits per int: "
            << std::numeric_limits<int>::digits
            << std::endl;

  return EXIT_SUCCESS;
}

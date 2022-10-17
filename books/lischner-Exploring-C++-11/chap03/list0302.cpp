/// list0302.cpp

#include <iostream>

int
main(void) {
  int x;
  while (std::cin >> x) {
    if (x % 2 == 0) {
      std::cout << x << " is odd" << std::endl;
    }
    else {
      std::cout << x << " is even" << std::endl;
    }
  }

  return EXIT_SUCCESS;
}

/** Read the program and determine what */ 
#include <iostream>
#include <limits>

int
main(void) {
  int min{std::numeric_limits<int>::max()};
  int max{std::numeric_limits<int>::min()};
  bool any{false};
  int x;

  while (std::cin >> x) {
    any = true;
    if (x < min) min = x;
    if (x > max) max = x;
  }

  if (any)
    std::cout << "min = " << min
              <<  " max = " << max
              << std::endl;

  return EXIT_SUCCESS;
}

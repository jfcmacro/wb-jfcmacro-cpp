#include <iostream>
#include <string>

int
main(void) {
  std::string empty;
  std::cout << "|" << empty << "|\n";

  int noValue; // Any value on the stack

  std::cout << "|" << noValue << "|\n";

  int noValue2{}; // default value

  std::cout << "|" << noValue2 << "|\n";

  return EXIT_SUCCESS;
}

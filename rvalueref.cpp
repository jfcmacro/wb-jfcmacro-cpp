#include <iostream>
#include <cstdlib>

void f(int&&);

int
main() {
  int a = 10;

  f(a);
  std::cout << "a: " << a << std::endl;
  return EXIT_SUCCESS;
}

void
f(int&& b) {
  ++b;
  std::cout << "b: " << b << std::endl;
}

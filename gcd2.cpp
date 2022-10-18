#include <iostream>
#include <cstdlib>
#include <cassert>

int gcd2(int a, int b);

int
main(int argc, char *argv[]) {
  int x;
  int y;
  std::cin >> x >> y;
  assert(x > y);
  std::cout << "gcd2(" << x << "," << y << ")=" << gcd2(x,y) << std::endl;

  return EXIT_SUCCESS;
}

int gcd2(int a, int b) {
  int c;
 ciclo:
  c = a - b;
  std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
  if (c == 1) return c;
  if (c == b) return c;
  if (c < b) {
    a = b;
    b = c;
  }
  else a = c;
  goto ciclo;
  return c;
}

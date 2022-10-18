#include <iostream>
#include <cstdlib>
#include <cassert>

int gcd3(int a, int b);

int
main(int argc, char *argv[]) {
  int x;
  int y;
  std::cin >> x >> y;
  assert(x > y);
  std::cout << "gcd3(" << x << "," << y << ")=" << gcd3(x,y) << std::endl;

  return EXIT_SUCCESS;
}

int gcd3(int a, int b) {
  int c;
  c = a - b;
  while (c > 1 && c != b) {
    std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
    if (c < b) {
      a = b;
      b = c;
    }
    else a = c;
    c = a - b;
  }
  return c;
}

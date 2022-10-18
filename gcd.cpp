#include <iostream>
#include <cstdlib>

int gcd(int a, int b);

int
main(int argc, char *argv[]) {
  int x;
  int y;
  
  //  std::cout << "Enter two integer numbers: ";
               
  std::cin >> x >> y;

  std::cout << "gcd(" << x << "," << y << ")=" << gcd(x,y) << std::endl;

  return EXIT_SUCCESS;
}


int
gcd(int a, int b) {
  std::cout << "a: " << a << "b: " << b << std::endl;
  while (a != b) {
    if (a > b)
      a = a - b;
    else
      b = b - a;
    std::cout << "a: " << a << "b: " << b << std::endl;
  }
  return a;
}

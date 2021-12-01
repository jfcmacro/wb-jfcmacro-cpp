#include <iostream>
#include <cstdlib>

double expNat(double x) {
  double exp = 0.0;
  double nExp = 0.0;
  double diff = nExp - exp;
  double epsilon = 1.0e-10;
  double pot = 1.0;
  int    fac = 1;

  for (int n = 0; n < 12; n++) {
    nExp = exp + (pot/fac);
    pot *= x;
    fac *= (n+1);
    diff = nExp - exp;
    exp = nExp;
  }
  
  return exp;
}

int
main(int argc, char* argv[]) {
  
  for (int i = 0; i < 10; i ++) {
    std::cout << "e^" << i << "=" << expNat((double) i) << std::endl;
  }
  
  return EXIT_SUCCESS;
}


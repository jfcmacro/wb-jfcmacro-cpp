// Maximo comun divisor
#include <iostream>

using namespace std;

int
mcd(int x, int y) {

  if ((x % y)  == 0)
    return y;

  return mcd(y, x % y);
}

int
main(int argc, char *argv[]) {

  cout << "El máximo común divisor de 34 y 22 es: " << mcd(42,6) << endl;

}

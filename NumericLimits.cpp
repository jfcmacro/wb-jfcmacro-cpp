#include <limits>
#include <iostream>

using namespace std;

int
main() {
  cout << "long double más grande == " << numeric_limits<long double>::max() << endl
       << "double más grande == " << numeric_limits<double>::max() << endl
       << "float más grande == " << numeric_limits<float>::max() << endl
       << "long más grande  == " << numeric_limits<long int>::max() << endl;
  return 0;
}

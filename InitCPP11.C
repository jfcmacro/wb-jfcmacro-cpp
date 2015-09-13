#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int
main() {

  int a {10};
  int b[] {10,20,30};
  struct T {
    int a;
    int b[5];
  } eT1 {10, {1,2,3,4,5}};

  cout << "a=" << a << endl;

  for (int i = 0; i < sizeof(b) / sizeof(int); ++i) {
    
    cout << "b[" << i << "]=" << b[i] << endl;
  }

  cout << "eT1.a=" << eT1.a << endl;

  for (int i = 0; i < sizeof(eT1.b) / sizeof(int); ++i) {

    cout << "eT1.b[" << i << "]=" << eT1.b[i] << endl;
  }

  vector<int> v {1,2,3,4,5,6};

  for (auto e : v ) {
    cout << "e=" << e << endl;
  }

  complex<double> z {1,1};

  cout << "z=" << z << endl;
  return 0;
}

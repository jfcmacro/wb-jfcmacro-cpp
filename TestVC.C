#include <iostream>

using namespace std;

class NV {
  double a;
  double b;
public:
  NV() : a(1.1), b(1.1) { }
  NV(double a, double b) : a(a), b(b) {}
  double getA() const {
    return a;
  }
  double getB() const {
    return b;
  }
} nv1;

class WV {
  double a;
  double b;
public:
  WV() : a(1.1), b(1.1) { }
  // virtual ~WV() { }
  double getA() const {
    return a;
  }
  double getB() const {
    return b;
  }
} wv1;

int
main() {
  NV nv2(10.22, 20.2);
  WV wv2;
  NV* pnv = new NV();
  WV* pwv = new WV();
  NV arreglo[10] { {1.1,1.1}, {2.2,2.2}, {3.3,3.3}};
  cout << "int: " << sizeof(int) << endl;
  cout << "double: " << sizeof(double) << endl;
  cout << "nv1: " << sizeof(nv1) << endl;
  cout << "nv2: " << sizeof(nv2) << endl;
  cout << "pnv: " << sizeof(*pnv) << endl;
  cout << "wv1: " << sizeof(wv1) << endl;

  for (auto i = 0; i < sizeof(arreglo)/sizeof(NV); ++i) {
    cout << "arreglo[" << i << "].a=" << arreglo[i].getA() << endl;
  }
  return 0;
}

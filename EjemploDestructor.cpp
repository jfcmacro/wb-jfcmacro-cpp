#include <iostream>

using namespace std;

class A {
public:
  A();
  ~A();
  int* memoria();
private:
  int* mem;
};

int
main(void) {
  int *p;

  for (int i = 0; i < 10000000; ++i) 
  {
    A unA;
    p = unA.memoria();
    
    cout << hex << p << endl;
  }
}

A::A() {
  mem = new int[100000000];
}

A::~A() { }

int*
A::memoria() {
  return mem;
}


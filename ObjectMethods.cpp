#include <iostream>

using namespace std;

class A {
public:
  A(int i) : i(i) { }
  ~A() { }
  void show() const { cout << i << endl; }
private:
  int i;
};

void compareAnShow(A, A);


int
main() {

  A anAOne(10),
    anATwo(20);
  
  compareAnShow(anAOne, anATwo);
  anAOne = anATwo;
  compareAnShow(anAOne, anATwo);

  return 0;
}

void compareAnShow(A a, A b) {
  a.show();
  b.show();
}

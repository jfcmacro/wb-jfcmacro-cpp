#include <iostream>

using namespace std;

class Test {
public:
  Test();
  Test(int v);
  ~Test();
  void m();
private:
  int value;
};

Test::Test() : value(0) {
}

Test::Test(int v) : value(v) {
}

Test::~Test() {
  cout << "This object has left to live " << value << endl;
}

// void Test::m() {
//   value++;
// }

namespace NS {
  ::Test test(1);
}

Test test;

int
main() {

  cout << "This program is ending" << endl;
  return 0;
}

#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

class X {
public:
  X(int x) {
    this->x = x;
  }
  int getX() const {
    return x;
  }
  void add(int i) {
    x = x + i;
  }
private:
  int x;
};

void
funcion(X &x) {
  x.add(5);
}

int
main(void) {

  vector<X> y;

  for (int i = 0; i < 14; i++) {

    X x(i);

    y.push_back(x);
  }

  cout << y.size() << endl;

  for_each(y.begin(), y.end(), funcion);

  cout << y[2].getX() << endl;
}

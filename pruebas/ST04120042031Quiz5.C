#include <iostream>
#include <string>

using namespace std;

void f(int& a) {
  cout << "int " << a << endl;
  return;
}

void f(char& a) {
  cout << "char " << a << endl;
  return;
}

int
main() {
  int i = 1;
  char c = 'c';
  f(i);
  f(c);
  return 0;
}

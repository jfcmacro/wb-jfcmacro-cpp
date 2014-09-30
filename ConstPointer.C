#include <iostream>

using namespace std;

int
main() {
  int x = 10;
  int *const p = &x;

  cout << "x: " << x << endl;
  cout << "*p: " << *p << endl;

  (*p)++;

  const int *q = &x;
  
  cout << "*q: " << *q << endl;
  q++;

  const int *const t = &x;

  (*t)++;
  return 0;
}

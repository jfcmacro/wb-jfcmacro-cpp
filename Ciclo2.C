#include <iostream>

using namespace std;

int
main() {
  int i;
  int n = 4;

  for (i = 0; i < n; ++i) {
    --n;
  }
  cout << i << endl;
}

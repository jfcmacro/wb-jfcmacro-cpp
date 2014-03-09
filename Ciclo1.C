#include <iostream>

using namespace std;

int
main() {
  int i = 1;
  int n = 3;
  while (i <= n) {
    if ((i % n) == 0) {
      ++i;
    }
  }
  cout << i << endl;
}

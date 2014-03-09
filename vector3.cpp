#include <iostream>

using namespace std;

const int MAX = 10;
int
main() {

  int v[10];
  int top = 0;

  for (int i = 0; i < MAX; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < MAX; i++) {
    cout << v[i] << endl;
  }

  return 0;
}

#include <iostream>

using namespace std;


const int MAX = 10;

int main() {

  X  v[10];
  int top = 0;

  for (;;) {
    if (top == MAX) break;
    cin >> v[top++];
  }

  top--;

  for (; top >= 0; top--) {
    cout << v[top] << endl;
  }

  return 0;
}

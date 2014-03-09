#include <iostream>

using namespace std;

int
main() {
  int factor = 5;
  int producto = 1;
  do {
    ++factor;
    producto *= factor;
    cout << "factor: " << factor << " producto: " << producto << endl;
  } while (factor <= 15);
  cout << producto << endl;
}

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10;

int
main() {

  bool vector[MAX];
  cout << "sizeof(bool): " << sizeof(bool) << endl;
  memset(vector, false, sizeof(vector));
  for (int i = 0; i < MAX; i++) {
    cout << i << " " << vector[i] << endl;
  }
  
  memset(vector, true, sizeof(vector));
  for (int i = 0; i < MAX; i++) {
    cout << i << " " << vector[i]<< endl;
  }
}

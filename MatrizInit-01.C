#include <iostream>

using namespace std;

int
main() {
  int m[4][3] = { {1,2,3},
		 {4,5,6},
		 {7,8,9},
                 {10,11,12}};
  int m2[4][3] = { {1,2},
                   {4,5},
                   {6,7}};

  cout << "Tamano: " << sizeof(m) << endl;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "m2[" << i << "," << j << "]=" << m2[i][j] << endl;
    }
  }


  return 0;
}

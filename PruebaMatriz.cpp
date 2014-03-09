#include<iostream>

using namespace std;

int*
cp(int* p, int ancho, int i, int j) {
  return p + ancho * i + j;
}

int
main() {
  int m[5][5];
  int *pM;
  int i, j;

  pM = (int *) m;

  i = 0; j = 0;
  cout << "m[" << i << "][" << j << "]" << &m[i][j] 
       << " equivalente " << cp(pM,5,i,j) << endl;
  i = 2; j = 4;
  cout << "m[" << i << "][" << j << "]" << &m[i][j] 
       << " equivalente " << cp(pM,5,i,j) << endl;
  m[3][4] = 4;
  cout << *cp(pM,5,3,4) << endl;
  return 0;
}

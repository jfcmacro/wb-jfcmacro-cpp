#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(void) {
  int i;
  string str;
  int corr = 0, incorr = 0;

  while (cin >> i >> str) {
     if (i == str.size()) corr++;
     else incorr++;
  }
  cout << "correctos: " << corr << " incorrectos: " << incorr << endl;
  return EXIT_SUCCESS;
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  int n;
  int ln, rn;
  string s1;

  ifstream in("entrada.in");

  in >> n;
  in >> ln;
  in >> rn;
  in >> s1;

  cout << n; cout << " ";
  cout << ln; cout << " ";
  cout << rn; cout << " ";
  cout << s1;
  cout << "\n";
}

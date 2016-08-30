#include <iostream>
#include <string>

using namespace std;

void un(string str) {

  int iv = 0;
  while (str[iv] != '*') iv++;

  string out;
  iv++;
  int ic = 0, is = 0;

  while (str[ic] != '*' or str[iv] != '\0') {
    if (str[ic] == '-') {
      out[is] = out[iv];
      iv++; is++;
    }
    else {
      if (str[ic] == '=') {
	out[is] = str[ic];
	is++; ic++;
      }

      out[is] = str[ic];
      is++; ic++;
      out[is] = str[iv];
      iv++;
      is++;
    }
  }
  out[is] = '\0';
  cout << out << endl;
}

int
main() {

  string uno("hlm=nd*oau");

  un(uno);

  return 0;
}

#include <iostream>
#include <string>

using namespace std;

void un(string str) {

  int iv = 0;
  while (str[iv] != '*') iv++;

  char *out = new char[str.size() + 1];
  iv++;
  int ic = 0, is = 0;

  while (str[ic] != '*' or str[iv] != '\0') {
    if (str[ic] == '-') {
      out[is] = str[iv];
      iv++; is++;
      ic++;
    }
    else {
      if (str[ic] == '=') {
        ic++;
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

  string uno("hlm=nd*oauo");
  string dos("-=nt=sl-*aeea");

  un(uno);
  un(dos);

  return 0;
}

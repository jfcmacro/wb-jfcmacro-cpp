#include <iostream>
#include <cctype>

using namespace std;

int
main(void) {

  char c;
  c = cin.get();
  while (cin) {
    c = toupper(c);
    cout << c;
    c = cin.get();
  }

  return 0;
}

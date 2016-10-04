#include <iostream>

using namespace std;

int
main() {
  char nl1 = '\n', nl2 = '\012', nl3 = '\x0A', nl4 = 0xA, nl5 = 012, nl6 = '\u000a';

  cout << "nl1: " << nl1;
  cout << "nl2: " << nl2;
  cout << "nl3: " << nl3;
  cout << "nl4: " << nl4;
  cout << "nl5: " << nl5;
  cout << "nl6: " << nl6;
 
  return 0;
}

#include <iostream>
#include <ios>
#include <cstdlib>

using namespace std;

int
main(void) {
  cout << " " << cin.gcount();
  do {
    char c = cin.get();

    if (cin.eof() || cin.fail() || cin.bad()) break;

    cout << c;
  } while (true);

  return EXIT_SUCCESS;
}

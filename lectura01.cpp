#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main () {

  string line;

  while (getline(cin, line)) {
    cout << line << endl;
  }

  return EXIT_SUCCESS;
}

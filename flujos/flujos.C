#include <sstream>
#include <iostream>

using namespace std;

int
main() {

  ostringstream fs;

  fs << "programa " << 4 << " " << 5;

  cout << fs.str().c_str();

}

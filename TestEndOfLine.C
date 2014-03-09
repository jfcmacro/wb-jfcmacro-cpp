#include <iostream>
#include <sstream>

using namespace std;

int
main(int argc, char *argv[]) {

  string line;
  getline(cin, line);
  istream *pos = new istringstream(line);

  for (int i = 0; i < line.size() + 1; i++) {
    char c;
    c = pos->get();
    cout << int(c) << endl;
  }
  return 0;
}

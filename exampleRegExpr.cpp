#include <iostream>
#include <string>
#include <regex>

using namespace std;

int
main(int argc, const char* argv[]) {

  string s("cmd -arg1                  -arg2             arg3   filename   ");
  smatch m;
  regex e("(-?[:alpha:][[:alpha:][:digit:]]*)");

  while (regex_search(s,m,e)) {
    cout << m[0] << endl;
    s = m.suffix().str();
  }
 

  return 0;
}

#include <iostream>
#include <regex>

using namespace std;

int
main(int argc, const char* argv[]) {
  string cmd = "xclip -a -b --largo --muylargo     arg3";
  smatch m;
  regex e("-?-?\\w+");

  while(regex_search(cmd, m, e)) {
    for (auto x:m) cout << x << " ";
    cout << endl;
    cmd = m.suffix().str(); 
  }
}

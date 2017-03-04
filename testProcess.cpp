#include <iostream>
#include <string>
#include <vector>
#include "process.h"

using namespace std;

int
main(int argc, const char* argv[]) {

  string cmd1 = "xclip -selection c -o";

  ProgramInfo pi(cmd1);

  cout << pi.getCmd() << endl;

  for (auto s:pi.getArgs()) {
    cout << s << endl;
  }

  return 0;
}

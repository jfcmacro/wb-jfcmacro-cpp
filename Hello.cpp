#include <iostream>

using namespace std;

int
main(int argc, const char *argv[]) {
  
  cout << "Hello World!" << endl;
  cout << argv[0] << endl;
  for (int i = 1; i < argc; ++i) {
    cout << "arg[" << i << "]=" << argv[i] << endl;
  }
  return 0;
}

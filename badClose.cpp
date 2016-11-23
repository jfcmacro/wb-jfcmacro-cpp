#include <iostream>
#include <unistd.h>
#include <cstring>
#include <errno.h>

using namespace std;

int
main(int argch ,char *argv[]) {

  int value = -1;

  if (close(-1) == -1) {
    cerr << "Error: " << strerror(errno) << endl;
  }

  return 0;
}

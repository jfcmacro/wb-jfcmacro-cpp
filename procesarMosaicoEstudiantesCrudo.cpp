#include <iostream>
#include <stdlib.h>

using namespace std;

static void usage(const char *progname) {
  cerr << "Usage: " << progname << " <fichero> " << endl;
  exit(1);
}

int
main(int argc, const char* argv[]) {

  if (argc != 2) {
    usage(argv[0]);
  }
  
  ifstream fs(argv[1]);

  getline(fs,
}


  

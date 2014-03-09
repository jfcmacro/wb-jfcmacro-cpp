// contarHasta.

#include <iostream>
#include <cstdlib>

using namespace std;

void
usage0(char *progname) {
  cerr << "Uso: "
       << progname
       << " int"
       << " [int]"
       << endl;
}

void
usage1(char *progname) {
  usage0(progname);
  ::exit(1);
}

void
usage2(char *progname) {
  usage0(progname);
  cerr << "Error: desde >= hasta";
  exit(2);
}

int
main(int argc, char *argv[]) {

  int desde;
  int hasta;

  if (argc == 0 || argc > 3) {

    usage1(argv[0]);
  }
  else {

    if (argc == 2) {

      desde = 0;
      hasta = atoi(argv[1]);
    }
    else {

      desde = atoi(argv[1]);
      hasta = atoi(argv[2]);
    }

    if (!(desde < hasta)) {
      usage2(argv[0]);
    }
  }
  for (; desde <= hasta; desde++) {
    cout << desde << endl;
  }
}

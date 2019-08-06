#include <iostream>
#include <ios>
#include <cstdlib>

using namespace std;

enum READFAIL { ReadEOF, ReadBAD, ReadTooManyFailRead };
const int nMax = 10;

int
readFail(istream& in) {
  int i;
  int nr = 0;

  do {
    in >> i;

    if (in.good()) break;

    if (in.eof()) throw ReadEOF;

    if (in.bad()) throw ReadBAD;

    if (in.fail()) {
      nr++;
      if (nr == nMax) throw ReadTooManyFailRead;

      in.clear();
      char c = in.get();
    }

  } while (true);

  return i;
}

int
main(void) {
  cout << "Lectura" << endl;

  int i;

  try {
    i = readFail(cin);
  }
  catch (READFAIL& e) {
    cerr << "Error: " << e << endl;
    return -1;
  }

  cout << "Valor: " << i << endl;

  return EXIT_SUCCESS;
}

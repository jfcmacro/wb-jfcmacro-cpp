#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

static void usage(const char* progname) {
  cerr << "Usage: " << progname << " <fichero>" << endl;
  exit(1);
}

int
main(int argc, const char* argv[]) {

  if (argc != 2) {
    usage(argv[0]);
  }
  
  ifstream ifs(argv[1]);

  string line;

  while (getline(ifs,line)) {
    istringstream strstrm(line);
    string item;

    int i = 0;
    while (getline(strstrm, item, ',')) {
      switch(i) {
      case 1:
	cout << item << "|";
	break;
      case 2:
	cout << left << setw(35) << item << "|";
	break;
      case 6:
	cout << item;
	string st(item);
	cout << "|" << "244s" << st.substr(0, st.find("@") - 1);
      }
      ++i;
    }
    cout << endl;
  }

  return 0;
}

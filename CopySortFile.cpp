#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

void
usage(char *progname) {

  cerr << "Usage: " << progname << " from to" << endl;
  ::exit(1);
}

int
main(int argc, char *argv[]) {

  if (argc != 3) {
    usage(argv[0]);
  }

  string from(argv[1]);
  string to(argv[2]);
  
  ifstream fe(from.c_str());
  istream_iterator<string> ii(fe);
  istream_iterator<string> fdf;

  vector<string> b(ii, fdf);
  sort(b.begin(), b.end());

  ofstream fs(argv[2]);
  ostream_iterator<string> oo(fs, "\n");

  unique_copy(b.begin(), b.end(), oo);

  return !fe.eof() || !fs;
}

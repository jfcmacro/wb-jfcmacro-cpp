#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

struct Data {
  string test;
  string value;
};
int
main(int argc, char *argv[]) {

  int opt;
  extern char *optarg;
  Data data;

  while ((opt = getopt(argc, argv, "t:v:")) != -1) {
    switch (opt) {
    case 't':
      data.test = optarg;
      break;
    case 'v':
      data.value = optarg;
      break;
    }
  }
 
  cout << "data test: " << data.test
       << " data value: " << data.value
       << endl;

  return 0;
}

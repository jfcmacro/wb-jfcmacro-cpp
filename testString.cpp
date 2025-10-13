#include <string>
#include <iostream>
#include <unistd.h>

// using namespace std;

struct Data {
  std::string test;
  std::string value;
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
 
  std::cout << "data test: " << data.test
	    << " data value: " << data.value
	    << std::endl;

  std::string desktop {::getenv("XDG_CURRENT_DESKTOP")};
  std::cout << "desktop: " << desktop << std::endl;

  std::cout << "${desktop}==GNOME}=" << (desktop == "GNOME") << std::endl;

  return 0;
}

#include <iostream>

int
main(void) {
  std::string msg;
  std::getline(std::cin, msg);
  std::cout << "Hello, world."
	    << std::endl
	    << msg
	    << std::endl;
  return 0;
}

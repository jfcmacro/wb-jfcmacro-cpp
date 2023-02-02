// This is an weird example.
// It shows how a example of rvalue references, but this is not the way how
// to manage them
#include <iostream>
#include <cstdlib>

int
main(int argc, char *argv[]) {
  int count { 5 };
  int&& rtemp { count + 3 };
  int& rcount { count };
  std::cout << rtemp << std::endl;
  std::cout << rcount << std::endl;
  rcount += 2;
  std::cout << rtemp << std::endl;
  std::cout << rcount << std::endl;
  rtemp += 3;
  std::cout << rtemp << std::endl;
  std::cout << rcount << std::endl;

  return EXIT_SUCCESS;
}

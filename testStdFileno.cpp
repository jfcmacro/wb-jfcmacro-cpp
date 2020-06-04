#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int
main(void) {
 
  std::cout << "STDIN_FILENO"  << STDIN_FILENO  << std::endl;
  std::cout << "STDOUT_FILENO" << STDOUT_FILENO << std::endl;
  std::cout << "STDERR_FILENO" << STDERR_FILENO << std::endl;

  return EXIT_SUCCESS;
}

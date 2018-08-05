#include <iostream>
#include <string>
#include <cstdlib>

int
main(void) {
  std::string uno("uno");
  std::string dos("dos");
  std::string tres = uno + dos + ".tres";

  std::cout << uno << " "
            << dos << " "
            << tres << " " << std::endl;

  return EXIT_SUCCESS;
}

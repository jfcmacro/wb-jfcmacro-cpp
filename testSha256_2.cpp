#include <iostream>
#include <cstdlib>
#include "sha256base64.h"

int main(void) {

  std::string str, strhashed;

  for (;;) {
    std::cin >> str;

    if (!std::cin) break;

    computeHash(str, strhashed);

    std::cout << base64_encode(strhashed) << std::endl;
  }

  return EXIT_SUCCESS;
}

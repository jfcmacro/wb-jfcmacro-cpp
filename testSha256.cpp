#include <iostream>
#include <cstdlib>
#include "sha256base64.h"

int main() {
  std::string str;

  for (;;) {
    std::cin >> str;

    if (!std::cin) break;

    std::cout << base64_encode(sha256(str)) << std::endl;
  }

  return EXIT_SUCCESS;
}


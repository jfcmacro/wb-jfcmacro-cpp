#include <iostream>

int
main() {
  wchar_t c = L'é';
  std::cout << "El valor de '" << c << "' es " << int(c) << std::endl;
  return 0;
}

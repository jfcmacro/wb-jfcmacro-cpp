#include<iostream>
#include<cstdlib>

int
main(int argc, const char* argv[]) {

  char temp[30] = "llenoXXXXXX";
  char *nombre = mktemp(temp);
  std::cout << "nombre: " << nombre << std::endl;
  int i;
  std::cin >> i;
  return EXIT_SUCCESS;
}

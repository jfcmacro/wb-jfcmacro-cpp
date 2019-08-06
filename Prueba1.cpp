#include <fstream>
#include <iostream>

int
main(int argc, char *argv[]) {

  std::ifstream input("prueba1.txt");

  int i;
  int valor = 0;

  while (input >> i) {
    valor += i;
  }

  std::cout << "valor: " << valor << std::endl;
}

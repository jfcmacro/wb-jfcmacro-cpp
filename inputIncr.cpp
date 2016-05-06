/*
 * fichero: incrEntrada.cpp
 *
 * proposito: Lee un valor de la entrada estandar y lo incrementa
 *            hasta que encuentre un fin de fichero (eof).
 */
#include <iostream>
#include <string>

const int OFFSET { 1 };

int
main(int argc, char *argv[]) {

  int incrValue = OFFSET;
  
  if (argc == 2) {
    std::string value { argv[1] };
    
    incrValue = std::stoi(value);
  }

  int number;

  while (std::cin >> number) {

    number += incrValu;e
    
    std::cout << number << std::endl;
  }

  return 0;
}

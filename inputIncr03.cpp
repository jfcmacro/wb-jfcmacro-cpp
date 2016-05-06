/*
 * fichero: inputIncr03.cpp
 *
 * proposito: Lee un valor de la entrada estandar y lo incrementa
 *            hasta que encuentre un fin de fichero (eof).
 */
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
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

  while (read(STDIN_FILENO, &number, sizeof(number)) > 0) {

    number += incrValue;
    
    write(STDOUT_FILENO, &number, sizeof(number));
  }

  return 0;
}

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
#include "estructuras.h"
#include <stdio.h>

const int OFFSET { 1 };

int
main(int argc, char *argv[]) {

  int incrValue = OFFSET;
  
  if (argc == 2) {
    std::string value { argv[1] };
    
    incrValue = std::stoi(value);
  }
  
  int tamMsg;

  while (read(STDIN_FILENO, &tamMsg, sizeof(tamMsg)) > 0) {

    std::cerr << "Tamano a crear: " << tamMsg << std::endl;
    mensaje *msg = new mensaje[tamMsg];
    
    for (int i = 0; i < tamMsg; ++i) {
      read(STDIN_FILENO, &msg[i], sizeof(mensaje));
      sprintf(msg[i].nombre, "Cambiado por inputIncr04 %d", incrValue);
      incrValue++;
      msg[i].valor++;
    }

    tamMsg--;

    if (tamMsg == 0) break;
    
    write(STDOUT_FILENO, &tamMsg, sizeof(tamMsg));

    for (int i = 0; i < tamMsg; ++i) {
      write(STDOUT_FILENO, (msg + i), sizeof(mensaje));
    }
    delete[] msg;
  }

  return 0;
}

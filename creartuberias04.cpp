/*
 * fichero: Este ejemplo crea un tuberia y pasa un mensaje que es un entero
 *          que sera incrementado por el segundo proceso
 */
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/wait.h>
#include <errno.h>
#include "estructuras.h"

const int START { 10 };

int
main(int argc, const char *argv[]) {

  int number { START };
  int tamMensaje { START };
  
  if (argc == 3) {

    std::string start {argv[1] };
    number = std::stoi(start);

    std::string sTamMsg { argv[2] };
    tamMensaje = std::stoi(sTamMsg);
  }
  
  int tuberia1[2];
  int tuberia2[2];

  pipe(tuberia1);
  pipe(tuberia2);

  if (fork() == 0) { // inputIncr

    dup2(tuberia1[0], STDIN_FILENO);
    dup2(tuberia2[1], STDOUT_FILENO);
    close(tuberia1[0]);
    close(tuberia1[1]);
    close(tuberia2[0]);
    close(tuberia2[1]);
    execl("./inputIncr04", "inputIncr04", "4", NULL);
  }
  else { // Me
    
    dup2(tuberia1[1], STDOUT_FILENO);
    dup2(tuberia2[0], STDIN_FILENO);
    close(tuberia1[0]);
    close(tuberia1[1]);
    close(tuberia2[0]);
    close(tuberia2[1]);

    int errcode;
    std::cerr << "creartuberias03 numero enviado: " << tamMensaje << std::endl;
    bool nofirst = false;
    do {

      if (nofirst) {
	std::cerr << "Tamano recibido: " << tamMensaje << std::endl;
	for (int i = 0; i < tamMensaje; ++i) {
	  mensaje msg;
	  
	  read(STDIN_FILENO, &msg, sizeof(mensaje));
	  std::cerr << msg.nombre << std::endl;
	  std::cerr << msg.valor << std::endl;
	}
      }
      
      write(STDOUT_FILENO, &tamMensaje, sizeof(number));

      for (int i = 0; i < tamMensaje; ++i) {
	mensaje msg { "sin mensaje", number };
	number++;
	write(STDOUT_FILENO, &msg, sizeof(mensaje));
      }

      nofirst = true;
    } while ((errcode = read(STDIN_FILENO, &tamMensaje, sizeof(number))) > 0);

    if (errcode < 0) {
      std::cerr << "Numero de error: " << errno << std::endl;
    }
  }

  int status;

  wait(&status);
  
  return 0;
}

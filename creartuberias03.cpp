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

const int START { 10 };

int
main(int argc, const char *argv[]) {

  int number { START };
  
  if (argc == 2) {

    std::string start {argv[1] };
    
    number = stoi(start);
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
    execl("./inputIncr03", "inputIncr03", "2", NULL);
  }
  else { // Me
    
    dup2(tuberia1[1], STDOUT_FILENO);
    dup2(tuberia2[0], STDIN_FILENO);
    close(tuberia1[0]);
    close(tuberia1[1]);
    close(tuberia2[0]);
    close(tuberia2[1]);

    int errcode;
    
    do {
      std::cerr << "creartuberias03 numero enviado: " << number << std::endl;
      write(STDOUT_FILENO, &number, sizeof(number));
     
    } while ((errcode = read(STDIN_FILENO, &number, sizeof(number))) > 0);

    if (errcode < 0) {
      std::cerr << "Numero de error: " << errno << std::endl;
    }
  }

  int status;

  wait(&status);
  
  return 0;
}

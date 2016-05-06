/*
 * fichero: Este ejemplo crea un tuberia y pasa un mensaje que es un entero
 *          que sera incrementado por el segundo proceso
 */
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/wait.h>

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
    execl("./inputIncr", "inputIncr", "2", NULL);
  }
  else { // Me
    
    dup2(tuberia1[1], STDOUT_FILENO);
    dup2(tuberia2[0], STDIN_FILENO);
    close(tuberia1[0]);
    close(tuberia1[1]);
    close(tuberia2[0]);
    close(tuberia2[1]);
    
    do {
      std::cerr << "creartuberias02 numero enviado: " << number << std::endl;
      std::cout << number << std::endl;
    } while (std::cin >> number);
  }

  int status;

  wait(&status);
  
  return 0;
}

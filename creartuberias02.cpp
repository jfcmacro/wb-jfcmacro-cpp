/*
 * fichero: Este ejemplo crea un tuberia y pasa un mensaje que es un entero
 *          que sera incrementado por el segundo proceso
 */
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/wait.h>

using namespace std;

const int START { 10 };

int
main(int argc, const char *argv[]) {

  int number { START };
  
  if (argc == 2) {

    string start {argv[1] };
    
    number = stoi(start);
  }
  
  int tuberia1[2];
  int tuberia2[2];

  pipe(tuberia1);
  pipe(tuberia2);

  if (fork() == 0) { // inputIncr

    close(tuberia1[1]);
    close(tuberia2[0]);
    dup2(tuberia1[0], 0);
    dup2(tuberia2[1], 1);
    execl("./inputIncr", "inputIncr", "2", NULL);
  }
  else { // Me
    
    close(tuberia1[0]);
    close(tuberia2[1]);
    dup2(tuberia1[1], 1);
    dup2(tuberia2[0], 0);

    close(tuberia1[1]);
    close(tuberia2[0]);
    
    do {
      cerr << number << endl;
      cout << number;
      
    } while (cin >> number);
  }

  int status;

  wait(&status);
  
  return 0;
}

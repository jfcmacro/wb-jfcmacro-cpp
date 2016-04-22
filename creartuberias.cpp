#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int
main() {

  int tuberia1[2];
  int tuberia2[2];

  pipe(tuberia1);
  pipe(tuberia2);

  if (fork() == 0) { // Primer hijo
    close(tuberia2[0]);
    close(tuberia2[1]);
    close(tuberia1[0]);
    dup2(tuberia1[1],1);
    execlp("ls", "ls", NULL);
  }
  else if (fork() == 0) { // Segundo hijo
    close(tuberia1[1]);
    close(tuberia2[0]);
    dup2(tuberia1[0],0);
    dup2(tuberia2[1],1);
    execlp("grep", "grep", "^C", NULL);
  }
  else if (fork() == 0) { // Tercer hijo
    close(tuberia1[0]);
    close(tuberia1[1]);
    close(tuberia2[1]);
    dup2(tuberia2[0],0);
    execlp("wc", "wc", NULL);
  }

  //
  close(tuberia1[0]);
  close(tuberia1[1]);
  close(tuberia2[0]);
  close(tuberia2[1]);

  int status;

  wait(&status);
  wait(&status);
  wait(&status);
  
  return 0;
}

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int
main(void) {

  int tuberia[2];

  pipe(tuberia);

  pid_t proceso1, proceso2;
  
  if ((proceso2 = fork()) == 0) {
    // hijo2
    close(tuberia[1]);
    dup2(tuberia[0], 0);
    execl("./toupper", "toupper", NULL);
    _exit(1);
  }
  else {
    if ((proceso1 = fork()) == 0) {
      // hijo 1
      close(tuberia[0]);
      dup2(tuberia[1], 1);
      execl("/usr/bin/find", "find", "/usr", "-name", "*.h", NULL);
      _exit(1);
    }
  }

  close(tuberia[1]);
  close(tuberia[0]);

  int status;

  waitpid(proceso2, &status, 0);
  waitpid(proceso1, &status, 0);
  return 0;
}

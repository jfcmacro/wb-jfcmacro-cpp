#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

int
main() {

  if (fork() == 0) {
    execl("./Hello", "Hello", "esto", "son", "los", "argumento", 0);
    std::cerr << "Esto fallo" << std::endl;
  }
  else {
    int status;

    wait(&status);
  }

  return 0;
}

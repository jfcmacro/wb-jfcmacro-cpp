#include <iostream>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

int
main() {

  pid_t pid[1000]; // Los que estan en ejecución
  
  int i = 0;

  cout << "quien soy yo: " << ::getpid() << endl;

  if ((pid[i] = ::fork())== 0) {
    /* Proceso hijo */
    ::execl("/bin/ls", "ls", "-l", "/tmp");
  }
  else {
    /* Proceso padre */
    int status;
    cout << "pid hijo: " <<  pid << " identificacion del grupo " << i <<endl;
    ::kill(pid[i], 9);
    ::waitpid(pid[i], &status, 0);
  }
  return 0;
}

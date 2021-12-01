#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

std::string processSha(std::string& msg);

int
main() {

  for(;;) {
    std::string str;
    std::cin >> str;

    if (!std::cin) break;

    std::string retstr = processSha(str);
    std::cout << retstr << std::endl;
  }

  return EXIT_SUCCESS;
}

std::string
processSha(std::string& msg) {
  int pcpsha[2];
  int pshabase[2];

  ::pipe(pcpsha);
  ::pipe(pshabase);

  pid_t shaPro;

  if ((shaPro = fork()) == 0) {

    ::dup2(pcpsha[0], STDIN_FILENO);
    ::dup2(pshabase[1], STDOUT_FILENO);
    ::close(pcpsha[1]);
    ::close(pcpsha[0]);
    ::close(pshabase[1]);
    ::close(pshabase[0]);
    ::execlp("sha256sum", "sha256sum", nullptr);
    ::exit(1);
  }

  pid_t basePro;

  int pbasecp[2];

  pipe(pbasecp);

  if ((basePro = fork()) == 0) {
    ::dup2(pshabase[0], STDIN_FILENO);
    ::dup2(pbasecp[1], STDOUT_FILENO);
    ::close(pcpsha[1]);
    ::close(pcpsha[0]);
    ::close(pshabase[1]);
    ::close(pshabase[0]);
    ::close(pbasecp[0]);
    ::close(pbasecp[1]);
    ::execlp("base64", "base64", "-w", "0", "-", nullptr);
    ::exit(1);
  }

  ::close(pcpsha[0]);
  ::close(pshabase[0]);
  ::close(pshabase[1]);
  ::close(pbasecp[1]);

  ::write(pcpsha[1], msg.c_str(), msg.size());

  ::close(pcpsha[1]);

  const int BUFFER_SIZE = 256;
  char buffer[BUFFER_SIZE];

  ssize_t nr = ::read(pbasecp[0], buffer, BUFFER_SIZE);
  buffer[nr] = '\0';
  ::close(pbasecp[0]);

  int status;

  waitpid(shaPro, &status, 0);

  waitpid(basePro, &status, 0);

  return buffer;
}

#include <ext/stdio_filebuf.h>
#include <unistd.h>
#include <cstdlib>
#include <regex>
#include <iostream>

using namespace std;

bool testDevelEnv(istream& in, bool &isAttach);

int
main(void) {

  pid_t child;
  int pipefd[2];

  pipe(pipefd);

  child = fork();

  if (child == 0) {
    dup2(pipefd[1], 1);
    close(pipefd[0]);
    close(pipefd[1]);
    execl("/usr/bin/tmux",
          "tmux",
          "list-sessions",
          NULL);
    exit(1);
  }
  else {
    close(pipefd[1]);
    __gnu_cxx::stdio_filebuf<char> filebuf(pipefd[0], ios::in);
    istream is(&filebuf);
    bool isAttach;
    
    if (testDevelEnv(is, isAttach)) {
      child = fork();
      if (child == 0) {
        if (!isAttach) {
          execl("/usr/bin/tmux",
                "tmux",
                "attach",
                "-t",
                "devel",
                NULL);
          exit(1);
        }
        else {
          exit(0);
        }
      }
    }
    else {
      child = fork();
      if (child == 0) {
        execl("/usr/bin/tmux",
              "tmux",
              "new",
              "-s",
              "devel",
              NULL);
        exit(1);
      }
    }
  }
  
  exit(0);
}

bool testDevelEnv(istream& in, bool &isAttach) {
  bool ret;
  isAttach = ret = false;

  while (true) {
    string line;
    getline(in,line);

    if (!in) break;
    
    string name(line.substr(0, line.find_first_of(':')));
    string attach(line.substr(line.find_last_of(' ') + 1, line.size()));

    if (name == "devel") {
      ret = true;
      
      if (attach == "(attached)") {
        
        isAttach = true;
      }
      
      break;
    }
  }

  return ret;
}

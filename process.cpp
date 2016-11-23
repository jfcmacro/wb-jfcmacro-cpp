#include "process.h"
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <errno.h>

ProgramInfo::ProgramInfo(string cmd,
                         vector<string> args) :
  cmd(cmd), args(args) {
}

ProgramInfo::~ProgramInfo() {
}


string
ProgramInfo::getCmd() const {
  return cmd;
}

vector<string>
ProgramInfo::getArgs() const {
  return args;
}

unsigned int
ProgramInfo::getNroArgs() const {
  return args.size();
}

string
ProgramInfo::getArg(unsigned int pos) const {
  return args[pos];
}

void
closingArrayPipes(int **pipes, int n, int noClose) {
  
 for (unsigned int i = 0; i < n; ++i) {
   
    // if (i == 0) {
    //   close(pipes[i][0]);
    // }
    // else if (i == n - 1) {
    //   close(pipes[i][1]);
    // }
    // else {
    //   close(pipes[i][0]);
    //   close(pipes[i][1]);
    // }
   if (i == noClose) continue;
   
   close(pipes[i][0]);
   close(pipes[i][1]);
  }
}

void
closingArrayPipesExcEdges(int **pipes, int n) {
  
 for (unsigned int i = 0; i < n; ++i) {
   
    if (i == 0) {
      close(pipes[i][0]);
    }
    else if (i == n - 1) {
      close(pipes[i][1]);
    }
    else {
      close(pipes[i][0]);
      close(pipes[i][1]);
    }
  }
}

void
createProcessPipe(const vector<ProgramInfo>& programs,
                  const int pipeIn[2],
                  const int pipeOut[2],
                  vector<pid_t>& pidList) {

  int **pipes = new int*[programs.size()+1];
  
  for (unsigned int i = 0; i < programs.size() + 1; ++i) {
    pipes[i] = new int[2];
    
    // if ((i != 0) and (i != programs.size())) {
    //  cerr << "creating on i: " << i << endl;
    ::pipe(pipes[i]);
    // }
  }
  
  // pipes[0][0] = pipeIn[0];
  // pipes[0][1] = pipeIn[1];
  // pipes[programs.size()][0] = pipeOut[0];
  // pipes[programs.size()][1] = pipeOut[1];
    
  pidList.clear();
  for (unsigned int i = 0; i < programs.size(); ++i) {
    pidList.push_back(fork());
    
    if (pidList[i] == 0) {

      dup2(pipes[i][0], 0);
      dup2(pipes[i+1][1], 1);

      closingArrayPipes(pipes, programs.size() + 1, i);

      char **cmdArgs = new char*[programs[i].getArgs().size()+2];
      
      cmdArgs[0] = createCopyChar(programs[i].getCmd());

      unsigned int k = 1;
      for (unsigned int j = 0; j < programs[i].getArgs().size(); ++k,++j) {
        
        cmdArgs[k] = createCopyChar(programs[i].getArg(j));
      }
    
      cmdArgs[k] = NULL;

      execvp(cmdArgs[0], cmdArgs);

      cerr << "This cannot happen here because: " << errno
           << " " << strerror(errno) << endl;

      _exit(20);
    }
  }

  // closingArrayPipesExcEdges(pipes, programs.size() + 1);
  closingArrayPipes(pipes, programs.size() + 1, -1);

  delete []pipes;
  // for (unsigned int i = 0; i < programs.size()+1; ++i) {

  //   if (i == 0) {
  //     close(pipes[i][0]);
  //   }
  //   else if (i == programs.size()) {
  //     close(pipes[i][1]);
  //   }
  //   else {
  //     close(pipes[i][0]);
  //     close(pipes[i][1]);
  //   }
  // }  
}

char* createCopyChar(const string& arg) {
  char *ret = new char[arg.size() + 1];
  ::strcpy(ret, arg.c_str());
  return ret;
}

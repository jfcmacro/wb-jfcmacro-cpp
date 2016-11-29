#include "process.h"
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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

// ChainedProcessInfo::ChainedProcessInfo() :
//   active(true), in(-1), out(-1) {
// }

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

void
createChainedPipeProcess(const vector<ProgramInfo>& programs,
                         const string& inFileName,
                         const string& outFileName,
                         int inOut[2],
                         vector<pid_t>& pidList) {
  int pipeIn[2];
  int pipeOut[2];

  if (inFileName.size() != 0) {

    struct stat inStatFile;

    if (stat(inFileName.c_str(), &inStatFile) == -1) {
      throw CPPE_INPUT_FILE_DOES_NOT_EXIST;
    }

    if (!S_ISREG(inStatFile.st_mode)) {
      throw CPPE_INPUT_FILE_IS_NOT_REGULAR;
    }

    if (!(inStatFile.st_mode & S_IRUSR)) {
      throw CPPE_INPUT_FILE_HAS_NOT_PERMISSIONS;
    }

    if ((pipeIn[0] = open(inFileName.c_str(),
                          O_RDONLY)) == -1) {
      throw CPPE_INPUT_FILE_NOT_OPEN;
    }

    inOut[1] = pipeIn[1] = -1;
  }
  else {

    pipe(pipeIn);
    inOut[1] = pipeIn[1];
  }

  if (outFileName.size() != 0 and programs.size() == 1) {
    struct stat outStatFile;

    if (stat(outFileName.c_str(), &outStatFile) == -1) {

      if ((pipeOut[1] = creat(outFileName.c_str(),
                              S_IRUSR | S_IWUSR)) == -1) {
        throw CPPE_OUTFILE_CANNOT_BE_CREATED;
      }
    }
    else {
      if (!(outStatFile.st_mode & S_IRUSR &
            outStatFile.st_mode & S_IWUSR)) {

        throw CPPE_OUTFILE_HAS_NOT_CORRECT_PERMISSIONS;
      }

      if ((pipeOut[1] = open(outFileName.c_str(),
                             O_TRUNC | O_APPEND,
                             S_IRUSR | S_IWUSR)) == -1) {

        throw CPPE_OUTFILE_CANNOT_BE_OPENED;
      }
    }

    inOut[0] = -1;
  }
  else {
    pipe(pipeOut);
    inOut[0] = pipeOut[0];
  }

  pidList.clear();

  for (unsigned int i = 0; i < programs.size(); ++i) {
    pidList.push_back(fork());

    if (pidList[i] == 0) {
      dup2(pipeIn[0], 0);
      dup2(pipeOut[1], 1);

      close(pipeIn[1]);
      close(pipeOut[0]);
      close(inOut[0]);
      close(inOut[1]);

      char **cmdArgs = new char*[programs[i].getArgs().size()+2];

      cmdArgs[0] = createCopyChar(programs[i].getCmd());

      unsigned int k = 1;
      for (unsigned int j = 0; j < programs[i].getArgs().size();
           ++k,++j) {

        cmdArgs[k] = createCopyChar(programs[i].getArg(j));
      }

      cmdArgs[k] = NULL;

      execvp(cmdArgs[0], cmdArgs);

      cerr << "This cannot happen here because: " << errno
           << " " << strerror(errno) << endl;

      _exit(20);

    }
    else {

      if (inOut[1] != pipeIn[1]) {
        close(pipeIn[1]);
      }

      close(pipeIn[0]);
      pipeIn[0] = pipeOut[0];
      pipeIn[1] = pipeOut[1];

      if (i + 1 != programs.size()) {
        pipe(pipeOut);
      }
      else {
        inOut[0] = pipeOut[0];
        close(pipeOut[1]);
      }
    }
  }
}

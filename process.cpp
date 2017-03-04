#include "process.h"
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <regex>

ProgramInfo::ProgramInfo(string cmd,
                         vector<string> args) :
  cmd(cmd), args(args) {
}

ProgramInfo::ProgramInfo(string cmd) : cmd(), args() {
  smatch m;
  regex e("([^ ]*)");

  bool first = true;
  while (regex_search(cmd,m,e)) {
    if (first) {
      this->cmd = m[0];
      first = false;
    }
    else {
      this->args.push_back(m[0]);
    }
    cmd = m.suffix().str();
  }
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

// void
// closingArrayPipes(int **pipes, int n, int noClose) {

//   for (unsigned int i = 0; i < n; ++i) {

//     // if (i == 0) {
//     //   close(pipes[i][0]);
//     // }
//     // else if (i == n - 1) {
//     //   close(pipes[i][1]);
//     // }
//     // else {
//     //   close(pipes[i][0]);
//     //   close(pipes[i][1]);
//     // }
//     if (i == noClose) continue;

//     close(pipes[i][0]);
//     close(pipes[i][1]);
//   }
// }

// void
// closingArrayPipesExcEdges(int **pipes, int n) {

//   for (unsigned int i = 0; i < n; ++i) {

//     if (i == 0) {
//       close(pipes[i][0]);
//     }
//     else if (i == n - 1) {
//       close(pipes[i][1]);
//     }
//     else {
//       close(pipes[i][0]);
//       close(pipes[i][1]);
//     }
//   }
// }

// void
// createProcessPipe(const vector<ProgramInfo>& programs,
//                   const int pipeIn[2],
//                   const int pipeOut[2],
//                   vector<pid_t>& pidList) {

//   int **pipes = new int*[programs.size()+1];

//   for (unsigned int i = 0; i < programs.size() + 1; ++i) {
//     pipes[i] = new int[2];

//     // if ((i != 0) and (i != programs.size())) {
//     //  cerr << "creating on i: " << i << endl;
//     ::pipe(pipes[i]);
//     // }
//   }

//   // pipes[0][0] = pipeIn[0];
//   // pipes[0][1] = pipeIn[1];
//   // pipes[programs.size()][0] = pipeOut[0];
//   // pipes[programs.size()][1] = pipeOut[1];

//   pidList.clear();
//   for (unsigned int i = 0; i < programs.size(); ++i) {
//     pidList.push_back(fork());

//     if (pidList[i] == 0) {

//       dup2(pipes[i][0], 0);
//       dup2(pipes[i+1][1], 1);

//       closingArrayPipes(pipes, programs.size() + 1, i);

//       char **cmdArgs = new char*[programs[i].getArgs().size()+2];

//       cmdArgs[0] = createCopyChar(programs[i].getCmd());

//       unsigned int k = 1;
//       for (unsigned int j = 0; j < programs[i].getArgs().size(); ++k,++j) {

//         cmdArgs[k] = createCopyChar(programs[i].getArg(j));
//       }

//       cmdArgs[k] = NULL;

//       execvp(cmdArgs[0], cmdArgs);

//       cerr << "This cannot happen here because: " << errno
//            << " " << strerror(errno) << endl;

//       _exit(20);
//     }
//   }

//   // closingArrayPipesExcEdges(pipes, programs.size() + 1);
//   closingArrayPipes(pipes, programs.size() + 1, -1);

//   delete []pipes;
//   // for (unsigned int i = 0; i < programs.size()+1; ++i) {

//   //   if (i == 0) {
//   //     close(pipes[i][0]);
//   //   }
//   //   else if (i == programs.size()) {
//   //     close(pipes[i][1]);
//   //   }
//   //   else {
//   //     close(pipes[i][0]);
//   //     close(pipes[i][1]);
//   //   }
//   // }
// }

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

// char* createCopyChar(const string& arg) {
//   char *ret = new char[arg.size() + 1];
//   ::strcpy(ret, arg.c_str());
//   return ret;
// }

// char* createCopyChar(const string& arg) {
//   char *ret = new char[arg.size() + 1];
//   ::strcpy(ret, arg.c_str());
//   return ret;
// }


int launchProcess(const string& cmd,
                  vector<string> args,
                  const string& msgError) {

  if (fork() == 0) {

    char **cmdArgs = new char*[args.size()+2];

    cmdArgs[0] = createCopyChar(cmd);

    unsigned int i = 1;
    for (unsigned int j = 0; j < args.size(); ++i,++j) {
      
      cmdArgs[i] = createCopyChar(args[j]);
    }
    
    cmdArgs[i] = NULL;

    execvp(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
         << " " << strerror(errno) << endl;
    
    exit(20);
  }

  int status;
  ::wait(&status);

  if (WIFEXITED(status)) {
    if (WEXITSTATUS(status) != 0) {
      cerr << msgError
           << " status: " << WEXITSTATUS(status)
           << endl;
      return WEXITSTATUS(status);
    }
    return 0;
  }
  return -1;
}

int launchProcessInFile(const string& inFile,
                        const string& cmd, vector<string> args,
                        const string& msgError) {

  cout << "cmd: " << cmd << " ";

  for (unsigned int i = 0; i < args.size(); ++i) {
    cout << args[i];
    if (i + 1 == args.size())  cout << " ";
  }

  cout << endl;

  pid_t pidChild;

  if ((pidChild = fork()) == 0) { /* First Child */

    char **cmdArgs = new char*[args.size()+2];

    cmdArgs[0] = createCopyChar(cmd);

    unsigned int i = 1;
    for (unsigned int j = 0; j < args.size(); ++i,++j) {

      cmdArgs[i] = createCopyChar(args[j]);
    }

    cmdArgs[i] = NULL;

    int fd;

    if ((fd = open(inFile.c_str(), O_RDONLY)) == -1) {
      cerr << "File: " << inFile << " cannot be opened "
           << " because " << errno << endl;
      exit(21);
    }

    ::dup2(fd, STDIN_FILENO);
    // ::dup2(pipefds[1], STDOUT_FILENO);

    ::close(fd);
    // ::close(pipefds[0]);
    // ::close(pipefds[1]);

    ::execv(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
         << " " << strerror(errno) << endl;
    exit(30);
  }

  int statChild;
  waitpid(pidChild, &statChild, 0);

  cout << "child end status: " << statChild <<  endl;

  if (WIFEXITED(statChild)) {
    if (WEXITSTATUS(statChild) != 0) {
      cerr << msgError
           << " status child: " << WEXITSTATUS(statChild)
        ;
    }
  }

  return -1;
}


int launchTwoProcessInFile(const string& inFile,
                           const string& cmd1, vector<string> args1,
                           const string& cmd2, vector<string> args2,
                           const string& msgError) {

  cout << "cmd1: " << cmd1 << " ";
  for (unsigned int i = 0; i < args1.size(); ++i) {
    cout << args1[i];
    if (i + 1 == args1.size())  cout << " ";
  }
  cout << endl;

  cout << "cmd2: " << cmd2 << " ";
  for (unsigned int i = 0; i < args2.size(); ++i) {
    cout << args2[i];
    if (i + 1 != args2.size())  cout << " ";
  }
  cout << endl;

  int pipefds[2];

  ::pipe(pipefds);

  pid_t pidChild1;

  if ((pidChild1 = fork()) == 0) { /* First Child */

    char **cmdArgs = new char*[args1.size()+2];

    cmdArgs[0] = createCopyChar(cmd1);

    unsigned int i = 1;
    for (unsigned int j = 0; j < args1.size(); ++i,++j) {

      cmdArgs[i] = createCopyChar(args1[j]);
    }

    cmdArgs[i] = NULL;

    int fd;

    if ((fd = open(inFile.c_str(), O_RDONLY)) == -1) {
      cerr << "File: " << inFile << " cannot be opened "
           << " because " << errno << endl;
      exit(21);
    }

    ::dup2(fd, STDIN_FILENO);
    ::dup2(pipefds[1], STDOUT_FILENO);

    ::close(fd);
    ::close(pipefds[0]);
    ::close(pipefds[1]);

    ::execv(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
         << " " << strerror(errno) << endl;
    exit(30);
  }

  pid_t pidChild2;

  if ((pidChild2 = fork()) == 0) { /* Child 2*/
    char **cmdArgs = new char*[args2.size()+2];

    cmdArgs[0] = createCopyChar(cmd2);

    unsigned int i = 1;
    for (unsigned int j = 0; j < args2.size(); ++i,++j) {

      cmdArgs[i] = createCopyChar(args2[j]);
    }
    cmdArgs[i] = NULL;

    ::dup2(pipefds[0], STDIN_FILENO);

    ::close(pipefds[0]);
    ::close(pipefds[1]);

    execvp(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
         << " " << strerror(errno) << endl;
    exit(40);
  }

  ::close(pipefds[0]);
  ::close(pipefds[1]);

  int statChild1;
  waitpid(pidChild1, &statChild1, 0);

  cout << "child1 end status: " << statChild1 <<  endl;

  if (WIFEXITED(statChild1)) {
    if (WEXITSTATUS(statChild1) != 0) {
      cerr << msgError
           << " status child 1: " << WEXITSTATUS(statChild1)
           << endl;
    }
  }

  int statChild2;

  waitpid(pidChild2, &statChild2, 0);

  cout << "child2 end status: " << statChild2 << endl;

  if (WIFEXITED(statChild2)) {
    if (WEXITSTATUS(statChild2) != 0) {
      cerr << msgError
           << " status child 2: " << WEXITSTATUS(statChild2)
           << endl;
      return WEXITSTATUS(statChild2);
    }
    return WEXITSTATUS(statChild2);
  }
  return -1;
}

int launchTwoProcess(const string& cmd1, vector<string> args1,
                     const string& cmd2, vector<string> args2,
                     const string& msgError) {

  cout << "cmd1: " << cmd1 << " ";
  for (unsigned int i = 0; i < args1.size(); ++i) {
    cout << args1[i];
    if (i + 1 == args1.size())  cout << " ";
  }
  cout << endl;

  cout << "cmd2: " << cmd2 << " ";
  for (unsigned int i = 0; i < args2.size(); ++i) {
    cout << args2[i];
    if (i + 1 != args2.size())  cout << " ";
  }
  cout << endl;

  int pipefds[2];

  ::pipe(pipefds);

  pid_t pidChild1;

  if ((pidChild1 = fork()) == 0) { /* First Child */

    char **cmdArgs = new char*[args1.size()+2];

    cmdArgs[0] = createCopyChar(cmd1);

    unsigned int i = 1;
    for (unsigned int j = 0; j < args1.size(); ++i,++j) {

      cmdArgs[i] = createCopyChar(args1[j]);
    }

    cmdArgs[i] = NULL;

    // int fd;

    // if ((fd = open(inFile.c_str(), O_RDONLY)) == -1) {
    //   cerr << "File: " << inFile << " cannot be opened "
    //        << " because " << errno << endl;
    //   exit(21);
    // }

    // ::dup2(fd, STDIN_FILENO);
    ::dup2(pipefds[1], STDOUT_FILENO);

    // ::close(fd);
    ::close(pipefds[0]);
    ::close(pipefds[1]);

    ::execv(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
         << " " << strerror(errno) << endl;
    exit(30);
  }

  pid_t pidChild2;

  if ((pidChild2 = fork()) == 0) { /* Child 2*/
    char **cmdArgs = new char*[args2.size()+2];

    cmdArgs[0] = createCopyChar(cmd2);

    unsigned int i = 1;
    for (unsigned int j = 0; j < args2.size(); ++i,++j) {

      cmdArgs[i] = createCopyChar(args2[j]);
    }
    cmdArgs[i] = NULL;

    ::dup2(pipefds[0], STDIN_FILENO);

    ::close(pipefds[0]);
    ::close(pipefds[1]);

    execvp(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
         << " " << strerror(errno) << endl;
    exit(40);
  }

  ::close(pipefds[0]);
  ::close(pipefds[1]);

  int statChild1;
  waitpid(pidChild1, &statChild1, 0);

  cout << "child1 end status: " << statChild1 <<  endl;

  if (WIFEXITED(statChild1)) {
    if (WEXITSTATUS(statChild1) != 0) {
      cerr << msgError
           << " status child 1: " << WEXITSTATUS(statChild1)
           << endl;
    }
  }

  int statChild2;

  waitpid(pidChild2, &statChild2, 0);

  cout << "child2 end status: " << statChild2 << endl;

  if (WIFEXITED(statChild2)) {
    if (WEXITSTATUS(statChild2) != 0) {
      cerr << msgError
           << " status child 2: " << WEXITSTATUS(statChild2)
           << endl;
      return WEXITSTATUS(statChild2);
    }
    return WEXITSTATUS(statChild2);
  }
  return -1;
}

// bool existsFile(const string& file) {
//   struct stat statBuffer;

//   if (stat(file.c_str(), &statBuffer) != 0) {
//     return false;
//   }

//   return S_ISREG(statBuffer.st_mode);
// }

// bool existsLocalFile(const string &file) {
//   string localfile("./");

//   localfile += file;

//   return existsFile(localfile);
// }

// bool existsDir(const string& dir) {
//   struct stat statBuffer;

//   if (stat(dir.c_str(), &statBuffer) != 0) {
//     return false;
//   }

//   return S_ISDIR(statBuffer.st_mode);
// }

// bool existsLocalDir(const string& dir) {
//   string localdir("./");

//   localdir += dir;

//   return existsDir(localdir);
// }

// int chDirStr(const string& dir) {

//   return chdir(dir.c_str());
// }

// int chLocalDirStr(const string& dir) {

//   string localdir("./");

//   localdir += dir;

//   return chDirStr(localdir);
// }

// string& getCurrentDirName() {
//   const size_t DIRNAMESIZE = 1024;
//   char *currentDirName = new char[DIRNAMESIZE];

//   getcwd(currentDirName, DIRNAMESIZE);

//   string* strCurrentDirName = new string(currentDirName);
//   delete []currentDirName;
//   return *strCurrentDirName;
// }


PipelineProcess::PipelineProcess(vector<ProgramInfo> programInfo) :
  programInfo(programInfo) { }

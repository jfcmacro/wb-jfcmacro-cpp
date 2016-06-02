/*
 * fichero: launchTwoProcessIn.cpp
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stdlib.h>

using namespace std;

int launchTwoProcessInFile(const string& inFile,
			   const string& cmd1, vector<string> args1,
			   const string& cmd2, vector<string> args2,
			   const string& msgError);
int
main(int argc, char **argv) {

  string inFile("test_fracciones01.in");
  string cmd1("./fracciones");
  vector<string> args1;
  string cmd2("diff");
  vector<string> args2;
  string errorMsg("Error");

  args2.push_back("-");
  args2.push_back("test_fracciones01.out");
  
  if (launchTwoProcessInFile(inFile, cmd1, args1, cmd2, args2, errorMsg) != 0) {

    cerr << "Error" << endl;
  }
  
  return 0;
}

char* createCopyChar(const string& arg) {
  char *ret = new char[arg.size() + 1];
  ::strcpy(ret, arg.c_str());
  return ret;
}

int launchTwoProcessInFile(const string& inFile,
			   const string& cmd1, vector<string> args1,
			   const string& cmd2, vector<string> args2,
			   const string& msgError) {
  
  int pipefds[2];

  if (::pipe(pipefds) != 0) {
    cerr << "A very bad error" << endl;
    ::exit(10);
  }

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
      ::exit(21);
    }

    ::dup2(fd, STDIN_FILENO);
    ::dup2(pipefds[1], STDOUT_FILENO);
    
    ::close(fd);
    ::close(pipefds[0]);
    ::close(pipefds[1]);
    
    ::execv(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
	 << " " << strerror(errno) << endl;
    ::exit(30);
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
    
    ::execvp(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
	 << " " << strerror(errno) << endl;
    ::exit(40);
  }

  ::close(pipefds[0]);
  ::close(pipefds[1]);
  
  int statChild1;
  waitpid(pidChild1, &statChild1, 0);

  if (WIFEXITED(statChild1)) {
    if (WEXITSTATUS(statChild1) != 0) {
      cerr << msgError
	   << " status child 1: " << WEXITSTATUS(statChild1)
	   << endl;
    }
  }

  int statChild2;

  waitpid(pidChild2, &statChild2, 0);

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

bool existsFile(const string& file) {
  struct stat statBuffer;

  if (stat(file.c_str(), &statBuffer) != 0) {
    return false;
  }

  return S_ISREG(statBuffer.st_mode);
}

bool existsLocalFile(const string &file) {
  string localfile("./");

  localfile += file;

  return existsFile(localfile);
}

bool existsDir(const string& dir) {
  struct stat statBuffer;

  if (stat(dir.c_str(), &statBuffer) != 0) {
    return false;
  }

  return S_ISDIR(statBuffer.st_mode);
}

bool existsLocalDir(const string& dir) {
  string localdir("./");

  localdir += dir;

  return existsDir(localdir);
}

int chDirStr(const string& dir) {
  
  return chdir(dir.c_str());
}

int chLocalDirStr(const string& dir) {
  
  string localdir("./");

  localdir += dir;

  return chDirStr(localdir);
}



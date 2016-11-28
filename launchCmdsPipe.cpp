#include "process.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define COMMON_TEST

using namespace std;

int
main(int argc, char *argv[]) {

  vector<ProgramInfo> programs;

  vector<string> args;
  string cmd;

#ifdef COMMON_TEST
  cmd = "ls";
  args.push_back("-l");
  args.push_back("-a");
  args.push_back("-t");
// #else
//   cmd = "./testStdDesc";
//   args.push_back("1");
#endif
  
  ProgramInfo* pInfo = new ProgramInfo(cmd, args);

  programs.push_back(*pInfo);

#ifdef COMMON_TEST
  cmd = "sort";
  args.clear();
  args.push_back("-u");
  // #else
  //   cmd = "./testStdDesc";
  //   args.clear();
  //   args.push_back("2");
#endif
  
  pInfo = new ProgramInfo(cmd, args);
  programs.push_back(*pInfo);

#ifdef COMMON_TEST
  cmd = "grep";
  args.clear();
  args.push_back("^d");
// #else
//   cmd = "./testStdDesc";
//   args.clear();
//   args.push_back("3");
#endif
  
  pInfo = new ProgramInfo(cmd, args);
  programs.push_back(*pInfo);
  
  vector<pid_t> processIds;

  // int pipeIn[2];
  // int pipeOut[2];

  // ::pipe(pipeOut);
  // ::pipe(pipeIn);
  
  // pipeIn[0] = 0;
  // pipeIn[1] = 1;

  // createProcessPipe(programs,
  //                   pipeIn, pipeOut,
  //                   processIds);

  int inOut[2];
  createChainedPipeProcess(programs,
                           inOut,
                           processIds);

  close(inOut[1]);
  
  char c;
  int nrc;
  while ((nrc = read(inOut[0], &c, 1)) > 0) {
    cout << c;
  }

  if (nrc == -1) {
    cerr << "Input: " << strerror(errno) << endl;
  }

  for (vector<pid_t>::iterator it = processIds.begin();
       it != processIds.end(); ++it) {
    int status;
    waitpid(*it, &status, 0);
    cout << "pid: " << *it << " status: " <<  status << endl;
  }

  return 0;
}


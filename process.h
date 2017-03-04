#pragma once
#include <vector>
#include <string>

using namespace std;

class  ProgramInfo {
public:
  ProgramInfo(string cmd,
              vector<string> args);
  ProgramInfo(string cmd);
  ~ProgramInfo();
  string getCmd() const;
  vector<string> getArgs() const;
  string getArg(unsigned int pos) const;
  unsigned int getNroArgs() const;
private:
  string cmd;
  vector<string> args;
};

/* class ChainedProcessInfo { */
/*  public: */
/*   /\* ChainedProcessInfo(string& inFileName, string& outFileName); *\/ */
/*   /\* ChainedProcessInfo(string& fileName, bool isIn); *\/ */
/*   ChainedProcessInfo(); */
/*   ~ChainedProcessInfo(); */
/*   int[] getInOut(); */
/*   void setOutIn(); */
/*  private: */
/*   bool active; */
/*   int in; */
/*   int out; */
/*   int pipeIn[2]; */
/*   int pipeOut[2]; */
/* }; */

char* createCopyChar(const string& arg);

/* void closingArrayPipes(int **pipes, int n, int noClose); */
/* void closingArrayPipesExcEdges(int **pipes, int n); */


void createProcessPipe(const vector<ProgramInfo>& programs,
                       const int pipeIn[2],
                       const int pipeOut[2],
                       vector<pid_t>& pidList);

enum ChainedPipeProcessException {
  CPPE_INPUT_FILE_DOES_NOT_EXIST,
  CPPE_OUTPUT_FILE_EXITS,
  CPPE_INPUT_FILE_IS_NOT_REGULAR,
  CPPE_INPUT_FILE_HAS_NOT_PERMISSIONS,
  CPPE_INPUT_FILE_NOT_OPEN,
  CPPE_OUTFILE_CANNOT_BE_CREATED,
  CPPE_OUTFILE_HAS_NOT_CORRECT_PERMISSIONS,
  CPPE_OUTFILE_CANNOT_BE_OPENED
};

void createChainedPipeProcess(const vector<ProgramInfo>& programs,
                              const string& inFileName,
                              const string& outFileName,
                              int inOut[2],
                              vector<pid_t>& pidList);

// char* createCopyChar(const string& arg);

int launchProcess(const string& cmd,
                  vector<string> args,
                  const string& msgError);

int launchProcessInFile(const string& inFile,
                        const string& cmd, vector<string> args,
                        const string& msgError);

int launchTwoProcess(// const string& inFile,
                     const string& cmd1, vector<string> args1,
                     const string& cmd2, vector<string> args2,
                     const string& msgError);

int launchTwoProcessInFile(const string& inFile,
                           const string& cmd1, vector<string> args1,
                           const string& cmd2, vector<string> args2,
                           const string& msgError);

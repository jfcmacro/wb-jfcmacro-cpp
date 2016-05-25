/*
 * fichero: evalStdRepos.cpp
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include "stdreposutils.h"
#include "stdinfo.h"

using namespace std;

static void usage(const char* progname) {
  cerr << "Usage: " << progname << endl
       << "[--workdir[=]arg]" << endl
       << "[--reposdir[=]arg]" << endl
       << "[--username[=]arg]" << endl
       << "[--stdlst[=]stdcode[,stdcode]..." << endl
       << "[--resumen] <stdinfofile>" << endl;
  ::exit(1);
}

struct TestForElem {
  string inFile;
  string outFile;
  string cmdToTest;
  string cmdToDiff;
  TestForElem(string inFile, string outFile,
	      string cmdToTest, string cmdToDiff) :
    inFile(inFile), outFile(outFile),
    cmdToTest(cmdToTest), cmdToDiff(cmdToDiff) { }
};

struct ElemToEval {
  string id;
  string name;
  float value;
  string compileCmd;
  int nTests;
  TestForElem *tests;
  ElemToEval(string id, string name, float value,
	     string compileCmd, int nTests, TestForElem* tests) :
    id(id), name(name), value(value), compileCmd(compileCmd), nTests(nTests),
    tests(tests) { }
};

struct EvalUnit {
  string evalUnit;
  string name;
  string workdir;
  int nElemsToEval;
  ElemToEval *elemsToEval;
  EvalUnit(string evalUnit, string name, string workdir,
	   int nElemsToEval, ElemToEval* elemsToEval) :
    evalUnit(evalUnit), name(name), workdir(workdir), nElemsToEval(nElemsToEval),
    elemsToEval(elemsToEval) { }
};

TestForElem testFracciones01("test_fracciones01.in", "test_fracciones01.out", "./fracciones", "diff");
TestForElem testFracciones02("test_fracciones02.in", "test_fracciones02.out", "./fracciones", "diff");
TestForElem testFracciones03("test_fracciones03.in", "test_fracciones03.out", "./fracciones", "diff");
TestForElem testFracciones04("test_fracciones04.in", "test_fracciones04.out", "./fracciones", "diff");
TestForElem testFracciones05("test_fracciones05.in", "test_fracciones05.out", "./fracciones", "diff");
TestForElem testFracciones[] = { testFracciones01, testFracciones02, testFracciones03,
				 testFracciones04, testFracciones05 };
TestForElem testFracciones201("test_fracciones01.in", "test_fracciones01.out", "./fracciones2", "diff");
TestForElem testFracciones202("test_fracciones02.in", "test_fracciones02.out", "./fracciones2", "diff");
TestForElem testFracciones203("test_fracciones03.in", "test_fracciones03.out", "./fracciones2", "diff");
TestForElem testFracciones204("test_fracciones04.in", "test_fracciones04.out", "./fracciones2", "diff");
TestForElem testFracciones205("test_fracciones05.in", "test_fracciones05.out", "./fracciones2", "diff");
TestForElem testFracciones2[] = { testFracciones201, testFracciones202, testFracciones203,
				 testFracciones204, testFracciones205 }; 
TestForElem testBanco01("test_banco01.in", "test_banco01.out", "./banco", "diff");
TestForElem testBanco02("test_banco02.in", "test_banco02.out", "./banco", "diff");
TestForElem testBanco03("test_banco03.in", "test_banco03.out", "./banco", "diff");
TestForElem testBanco04("test_banco04.in", "test_banco04.out", "./banco", "diff");
TestForElem testBanco05("test_banco05.in", "test_banco05.out", "./banco", "diff");
TestForElem testBanco[] = { testBanco01, testBanco02, testBanco03, testBanco04,
			    testBanco05 };

ElemToEval fracciones("1", "fracciones", 0.35f, "make", 5, testFracciones);
ElemToEval fracciones2("2", "fracciones2", 0.35f, "make", 5, testFracciones2);
ElemToEval banco("3", "banco", 0.30f, "make", 5, testBanco);
ElemToEval elements[] = { fracciones, fracciones2, banco };

EvalUnit evalUnitMidTerm02("parciales",
			   "parcial2b",
			   "/home/fcardona/Workbench/eafit-st0244/parciales/parcial02/ST0244-2016-1-031-032-Programas-Parcial-02-b",
			   3,
			   elements);

void evalStdRepo(const string& stdId, const Estudiante& stdInfo,
		 const Options2& options, EvalUnit& evalUnit);

int launchProcess(const string& cmd, vector<string> args, const string& msgError);

int
main(int argc, char **argv) {

  int iniFich;
  Options2 options;

  iniFich = parseOptions2(options, argc, argv);
  
  if (iniFich == argc) {
    
    usage(argv[0]);
  }

  if (options.resumen) {
    cout << "--workdir: " << options.workdir << endl
	 << "--reposdir: " << options.reposdir << endl
	 << "--stdlst: ";
    for (vector<string>::iterator it = options.stdlst.begin();
	 it != options.stdlst.end();
	 ++it) {
      cout << *it;
      if ((it + 1) != options.stdlst.end())
	cout << ',';
    }
    cout  << endl
	  << "--username: " << options.username << endl
	  << "filename: " << argv[optind] << endl;
  }
   
  map <string,Estudiante> codEst;
  
  if (!obtenerEstudiantes(codEst, argv[optind])) {
    cerr << "student file input" << argv[optind] << endl;
    return 1;
  }

  cout << "Student loaded: " << codEst.size() << endl;

  if (chdir(options.workdir.c_str()) == 0) {
    struct stat buffer;

    if (stat(options.reposdir.c_str(),&buffer) != 0) {

      cerr << "reposdir: "
	   << options.reposdir
	   << " doesn't exist because errno: "
	   << errno << endl;
      exit(1);
    }

    if (chdir(options.reposdir.c_str()) == 0) {

      if (options.stdlst.empty()) {
	
	for (map<string,Estudiante>::iterator it = codEst.begin();
	     it != codEst.end();
	     ++it) {
	  
	  evalStdRepo(it->first, it->second, options, evalUnitMidTerm02);
	  
	  chdir(options.workdir.c_str());
	  chdir(options.reposdir.c_str());
	}
      }
      else {
	
	for (vector<string>::iterator it = options.stdlst.begin();
	     it != options.stdlst.end();
	     ++it) {

	  cout << "Searching for: " << *it << endl;
	  map<string,Estudiante>::iterator it2 = codEst.find(*it);

	  if (it2 != codEst.end()) {
	    
	    evalStdRepo(it2->first, it2->second, options, evalUnitMidTerm02);
	    chdir(options.workdir.c_str());
	    chdir(options.reposdir.c_str());
	  }
	  else {
	    cerr << "student id " << *it
		 << " doesn't exist"
		 << endl;
	  }
	}
      }
    }
  }
  else {
    
    cerr << "workdir: " << options.workdir << " doesn't exist "
	 << " errno: " << errno << endl;
    exit(1);
  }
  
  return 0;
}

char* createCopyChar(const string& arg) {
  char *ret = new char[arg.size() + 1];
  ::strcpy(ret, arg.c_str());
  return ret;
}

int launchProcess(const string& cmd, vector<string> args, const string& msgError) {

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
  wait(&status);
	
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

int launchTwoProcessIn1(const string& inFile,
			const string& cmd1, vector<string> args1,
			const string& cmd2, vector<string> args2,
			const string& msgError) {
  
  int pipeCmd1Cmd2[2];

  ::pipe(pipeCmd1Cmd2);

  pid_t pidChild1;

  cout << "cmd1: " << cmd1 << endl;
  cout << "cmd2: " << cmd2 << endl;

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
    ::dup2(pipeCmd1Cmd2[1], STDOUT_FILENO);
    
    ::close(fd);
    ::close(pipeCmd1Cmd2[0]);
    ::close(pipeCmd1Cmd2[1]);
    
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

    ::dup2(pipeCmd1Cmd2[0], STDIN_FILENO);
    
    ::close(pipeCmd1Cmd2[0]);
    ::close(pipeCmd1Cmd2[1]);
    
    execvp(cmdArgs[0], cmdArgs);

    cerr << "This cannot happen here because: " << errno
	 << " " << strerror(errno) << endl;
    exit(40);
  }

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


void evalStdRepo(const string& stdId, const Estudiante& stdInfo,
		 const Options2& options, EvalUnit& evalUnit) {
  
  if (!existsLocalDir(stdInfo.obtenerEmail())) {

    cerr << "Student: " << stdInfo.obtenerNombre() << endl
	 << " current directory: " << ::get_current_dir_name()
	 << " directory doesn't exist: " << stdInfo.obtenerEmail() << endl;
    return;
  }

  chdir(stdInfo.obtenerEmail().c_str());

  if (!existsLocalDir(evalUnit.evalUnit)) {
    cerr << "Student: " << stdInfo.obtenerNombre() << endl
	 << " directory doesn't exist: " << evalUnit.evalUnit << endl;
    return;
  }

  chLocalDirStr(evalUnit.evalUnit);

  if (!existsLocalDir(evalUnit.name)) {
    cerr << "Student: " << stdInfo.obtenerNombre() << endl
	 << " directory doesn't exist: " << evalUnit.evalUnit << endl;
    return;
  }

  chLocalDirStr(evalUnit.name);

  cout << "Student: " << stdInfo.obtenerNombre() << endl
       << "Current directory: " << ::get_current_dir_name() << endl;

  float totalStudent = 0.0f;
  
  for (int i = 0; i < evalUnit.nElemsToEval; ++i) {

    // Moviendo al directorio del parcial
    if (chLocalDirStr(evalUnit.elemsToEval[i].name.c_str()) != 0) {

      cerr << "Student: " << stdInfo.obtenerNombre() << endl
	   << " evaluating..." << endl
	   << " directory doesn't exist: " 
	   << evalUnit.elemsToEval[i].name.c_str() << endl
	   << " current directory: " << ::get_current_dir_name()
	   << endl;
      
      break;
    }

    cout << "Preparing cleaning compiling " << endl;
    
    vector<string> args;
    args.push_back("clean");
    string msg("compiling was not possible");
    
    if (launchProcess(evalUnit.elemsToEval[i].compileCmd, args, msg) != 0) {

      cerr << "Process cannot be cleaned" << endl;
      string up("..");
      chDirStr(up);
      break;
    }

    // make all
    cout << "Preparing compiling " << endl;
    
    args.clear();
    args.push_back("all");
    
    if (launchProcess(evalUnit.elemsToEval[i].compileCmd, args, msg) != 0) {
      
      string up("..");
      chDirStr(up);
      break;
    }

    // Compute units
    float unitElemToEval = evalUnit.elemsToEval[i].value / evalUnit.elemsToEval[i].nTests;
    float totalElemToEval = 0.0f;

    // preparing for copy test files
    string dirTest(evalUnit.workdir);
    dirTest += "/" + evalUnit.elemsToEval[i].name + "/";

    for (int k = 0; k < evalUnit.elemsToEval[i].nTests; ++k) {

      string inFile = evalUnit.elemsToEval[i].tests[k].inFile;
      string outFile = evalUnit.elemsToEval[i].tests[k].outFile;
      string srcInFile(dirTest);
      srcInFile += inFile;
      string srcOutFile(dirTest);
      srcOutFile += outFile;
      
      if (!existsFile(srcInFile) || !existsFile(srcOutFile)) {
	cerr << "SrcInFile: " << srcInFile << endl
	     << "SrcOutFile: " << srcOutFile << endl;
	continue;
      }

      // copy inFile
      ifstream srcIn(srcInFile.c_str());
      ofstream dstIn(inFile.c_str());

      dstIn << srcIn.rdbuf();

      srcIn.close();
      dstIn.close();

      // copy outFile
      ifstream srcOut(srcOutFile.c_str());
      ofstream dstOut(outFile.c_str());
	
      dstOut << srcOut.rdbuf();

      srcOut.close();
      dstOut.close();

      // string svnCmd("svn");
      // string svnErrMsg("Svn could add: ")
      // args.clear();
      // args.push_back("add");
      // args.push_back(inFile);
      // args.push_back(outFile);
      // svnErrMsg += inFile + " " + outFile;
      
      // if (launchProcess(svnCmd, args, svnErrMsg) != 0) {
      // 	cerr << "error: svn add " << inFile
      // 	     << " " << outFile << endl;
      // }

      // Preparing arguments for commands: 
      args.clear();
      
      vector<string> args2;
      args2.push_back("-");
      args2.push_back(outFile);
      int retCmdDiff;
      string msgCmdDiff("Error message");
      
      if ((retCmdDiff = launchTwoProcessIn1(inFile,
					    evalUnit.elemsToEval[i].tests[k].cmdToTest,
					    args,
					    evalUnit.elemsToEval[i].tests[k].cmdToDiff,
					    args2,
					    msgCmdDiff)) != 0) {
	switch(retCmdDiff) {
	case 1:
	  cout << "There are difference between expected output and obtained ouput"
	       << endl;
	  break;
	default:
	  cout << "Another kind of error: " << retCmdDiff << endl;
	  break;
	}
      }
      else {
	cout << "Test passed" << endl;
	totalElemToEval += unitElemToEval;
      }
    }

    totalStudent += totalElemToEval;

    cout << "Element Evalued: " << totalElemToEval << endl;
    string up("..");
    chDirStr(up);
  }

  cout << "Student: " << stdInfo.obtenerNombre()
       << " grade: " << totalStudent << endl;
  
  return;
}

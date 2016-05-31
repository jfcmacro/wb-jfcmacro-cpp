/*
 * fichero: evalStdRepos3.cpp
 * 
 * This version works with scripting languages
 *
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


TestForElem testComparc01("test_comparc01.in", "test_comparc01.out", "./comparc.rb", "diff");
TestForElem testComparc02("test_comparc02.in", "test_comparc02.out", "./comparc.rb", "diff");
TestForElem testComparc03("test_comparc03.in", "test_comparc03.out", "./comparc.rb", "diff");
TestForElem testComparc04("test_comparc04.in", "test_comparc04.out", "./comparc.rb", "diff");
TestForElem testComparc05("test_comparc05.in", "test_comparc05.out", "./comparc.rb", "diff");
TestForElem testComparc[] = { testComparc01, testComparc02, testComparc03,
			      testComparc04, testComparc05 };
TestForElem testFracciones01("test_fracciones01.in", "test_fracciones01.out", "./fracciones.rb", "diff");
TestForElem testFracciones02("test_fracciones02.in", "test_fracciones02.out", "./fracciones.rb", "diff");
TestForElem testFracciones03("test_fracciones03.in", "test_fracciones03.out", "./fracciones.rb", "diff");
TestForElem testFracciones04("test_fracciones04.in", "test_fracciones04.out", "./fracciones.rb", "diff");
TestForElem testFracciones05("test_fracciones05.in", "test_fracciones05.out", "./fracciones.rb", "diff");
TestForElem testFracciones[] = { testFracciones01, testFracciones02, testFracciones03,
				 testFracciones04, testFracciones05 };
TestForElem testReppor01("test_reppor01.in", "test_reppor01.out", "./reppor.rb", "diff");
TestForElem testReppor02("test_reppor02.in", "test_reppor02.out", "./reppor.rb", "diff");
TestForElem testReppor03("test_reppor03.in", "test_reppor03.out", "./reppor.rb", "diff");
TestForElem testReppor04("test_reppor04.in", "test_reppor04.out", "./reppor.rb", "diff");
TestForElem testReppor05("test_reppor05.in", "test_reppor05.out", "./reppor.rb", "diff");
TestForElem testReppor[] = { testReppor01, testReppor02, testReppor03, testReppor04,
			     testReppor05 };

TestForElem testControlPerillas01("test_controlPerilla01.in",
				  "test_controlPerilla01.out",
				  "./controlPerillas.rb",
				  "diff");
TestForElem testControlPerillas02("test_controlPerilla02.in",
				  "test_controlPerilla02.out",
				  "./controlPerillas.rb",
				  "diff");
TestForElem testControlPerillas03("test_controlPerilla03.in",
				  "test_controlPerilla03.out",
				  "./controlPerillas.rb", "diff");
TestForElem testControlPerillas04("test_controlPerilla04.in",
				  "test_controlPerilla04.out",
				  "./controlPerillas.rb",
				  "diff");
TestForElem testControlPerillas05("test_controlPerilla05.in",
				  "test_controlPerilla05.out",
				  "./controlPerillas.rb",
				  "diff");
TestForElem testControlPerillas[] = { testControlPerillas01, testControlPerillas02,
				      testControlPerillas03, testControlPerillas04,
				      testControlPerillas05 };

ElemToEval comparc("1", "comparc", 0.35f, "", 5, testComparc);
ElemToEval reppor("2", "reppor", 0.35f, "", 5, testReppor);
ElemToEval fracciones("3", "fracciones", 0.35f, "", 5, testFracciones);
ElemToEval perillas("4", "perillas", 0.25f, "", 5, testControlPerillas);
ElemToEval elements[] = { comparc, reppor, fracciones, perillas };

EvalUnit evalUnitMidTerm03("parciales",
			   "parcial03",
			   "/home/fcardona/Workbench/eafit-st0244/parciales/parcial03/ST0244-2016-1-031-032-Programas-Parcial-03",
			   4,
			   elements);

void evalStdRepo(const string& stdId, const Estudiante& stdInfo,
		 const Options2& options, EvalUnit& evalUnit);

int launchProcess(const string& cmd, vector<string> args, const string& msgError);

int launchTwoProcessInFile(const string& inFile,
			   const string& cmd1, vector<string> args1,
			   const string& cmd2, vector<string> args2,
			   const string& msgError);
int
main(int argc, char **argv) {

  int iniFich;
  Options2 options;

  // set srcfiles
  evalUnitMidTerm03.elemsToEval[0].srcfile.push_back("comparc.rb");
  evalUnitMidTerm03.elemsToEval[1].srcfile.push_back("reppor.rb");
  evalUnitMidTerm03.elemsToEval[2].srcfile.push_back("fracciones.rb");
  evalUnitMidTerm03.elemsToEval[3].srcfile.push_back("perilla10.rb");
  evalUnitMidTerm03.elemsToEval[3].srcfile.push_back("perilla10Enganche.rb");
  evalUnitMidTerm03.elemsToEval[3].srcfile.push_back("perillaLavadora.rb");
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
	  
	  evalStdRepo(it->first, it->second, options, evalUnitMidTerm03);
	  
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
	    
	    evalStdRepo(it2->first, it2->second, options, evalUnitMidTerm03);
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

    // cout << "Preparing cleaning compiling " << endl;
    
    vector<string> args;
    // args.push_back("clean");
    // string msg("compiling was not possible");
    
    // if (launchProcess(evalUnit.elemsToEval[i].compileCmd, args, msg) != 0) {

    //   cerr << "Process cannot be cleaned" << endl;
    //   string up("..");
    //   chDirStr(up);
    //   break;
    // }

    // // make all
    // cout << "Preparing compiling " << endl;
    
    // args.clear();
    // args.push_back("all");
    
    // if (launchProcess(evalUnit.elemsToEval[i].compileCmd, args, msg) != 0) {

    //   string cmdVi("vi");
    //   vector<string> argsVi;
    //   argsVi.push_back(evalUnit.elemsToEval[i].srcfile);
    //   string msgVi("Algo esta mal");

    //   cout << "Estudiante: " << stdInfo.obtenerNombre()
    // 	   << " fichero: " << evalUnit.elemsToEval[i].srcfile << endl
    // 	   << "<presione cualquier tecla>" << endl;
    //   cin.get();
    //   launchProcess(cmdVi, argsVi, msgVi);
    //   string up("..");
    //   chDirStr(up);
    //   break;
    // }

    // Compute units
    float unitElemToEval = evalUnit.elemsToEval[i].value / evalUnit.elemsToEval[i].nTests;
    float totalElemToEval = 0.0f;

    // preparing for copy test files
    bool anyTestFailed = false;
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
      
      if ((retCmdDiff = launchTwoProcessInFile(inFile,
					       evalUnit.elemsToEval[i].tests[k].cmdToTest,
					       args,
					       evalUnit.elemsToEval[i].tests[k].cmdToDiff,
					       args2,
					       msgCmdDiff)) != 0) {
	anyTestFailed = true;
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

    if (anyTestFailed) {
      
      string cmdVi("vi");
      vector<string> argsVi;
      string msgVi("Algo esta mal");
      
      for (unsigned int nsrcf = 0; nsrcf < evalUnit.elemsToEval[i].srcfile.size(); ++nsrcf) {
	argsVi.push_back(evalUnit.elemsToEval[i].srcfile[nsrcf]);

	cout << "Estudiante: " << stdInfo.obtenerNombre()
	     << " fichero: " << evalUnit.elemsToEval[i].srcfile[nsrcf] << endl
	     << "<presione cualquier tecla>" << endl;
	cin.get();
	
	launchProcess(cmdVi, argsVi, msgVi);
	argsVi.clear();
	cout << "Ready for the next file" << endl;
      }
    }
    
    cout << "Element Evalued: " << totalElemToEval << endl;
    string up("..");
    chDirStr(up);
  }

  cout << "Student: " << stdInfo.obtenerNombre()
       << " grade: " << totalStudent << endl;
  cout << "<Presione cualquier tecla para continuar>";
  cout.flush();
  cin.get();
  
  return;
}

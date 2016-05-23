/*
 * fichero: evalStdRepos.cpp
 */
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
  // TestForElem() :
  //   inFile(), outFile(), cmdToTest(), cmdToDiff() { }
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
  string name;
  string workdir;
  int nElemsToEval;
  ElemToEval *elemsToEval;
  EvalUnit(string name, string workdir,
	   int nElemsToEval, ElemToEval* elemsToEval) :
    name(name), workdir(workdir), nElemsToEval(nElemsToEval),
    elemsToEval(elemsToEval) { }
};

TestForElem testFracciones01("test_fracciones01.in", "test_fracciones01.out", "./fracciones", "diff -");
TestForElem testFracciones02("test_fracciones02.in", "test_fracciones02.out", "./fracciones", "diff -");
TestForElem testFracciones03("test_fracciones03.in", "test_fracciones03.out", "./fracciones", "diff -");
TestForElem testFracciones04("test_fracciones04.in", "test_fracciones04.out", "./fracciones", "diff -");
TestForElem testFracciones05("test_fracciones05.in", "test_fracciones05.out", "./fracciones", "diff -");
TestForElem testFracciones[] = { testFracciones01, testFracciones02, testFracciones03,
				 testFracciones04, testFracciones05 };
TestForElem testFracciones201("test_fracciones01.in", "test_fracciones01.out", "./fracciones2", "diff -");
TestForElem testFracciones202("test_fracciones02.in", "test_fracciones02.out", "./fracciones2", "diff -");
TestForElem testFracciones203("test_fracciones03.in", "test_fracciones03.out", "./fracciones2", "diff -");
TestForElem testFracciones204("test_fracciones04.in", "test_fracciones04.out", "./fracciones2", "diff -");
TestForElem testFracciones205("test_fracciones05.in", "test_fracciones05.out", "./fracciones2", "diff -");
TestForElem testFracciones2[] = { testFracciones201, testFracciones202, testFracciones203,
				 testFracciones204, testFracciones205 }; 
TestForElem testBanco01("test_banco01.in", "test_banco01.out", "./banco", "diff -");
TestForElem testBanco02("test_banco02.in", "test_banco02.out", "./banco", "diff -");
TestForElem testBanco03("test_banco03.in", "test_banco03.out", "./banco", "diff -");
TestForElem testBanco04("test_banco04.in", "test_banco04.out", "./banco", "diff -");
TestForElem testBanco05("test_banco05.in", "test_banco05.out", "./banco", "diff -");
TestForElem testBanco[] = { testBanco01, testBanco02, testBanco03, testBanco04,
			    testBanco05 };

ElemToEval fracciones("1", "fracciones", 0.35f, "make", 5, testFracciones);
ElemToEval fracciones2("2", "fracciones2", 0.35f, "make", 5, testFracciones2);
ElemToEval banco("3", "banco", 0.30f, "make", 5, testBanco);
ElemToEval elements[] = { fracciones, fracciones2, banco };

EvalUnit evalUnitMidTerm02("Parcial02b",
			   "/home/fcardona/Workbench/eafit-st0244/parciales/parcial02/ST0244-2016-1-031-032-Programas-Parcial-02-b",
			   3, elements);

void evalStdRepo(const string& stdId, const Estudiante& stdInfo,
		 const Options2& options, EvalUnit& evalUnit);

int lauchProcess(const string& cmd, vector<string> args);

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
	}
      }
      else {
	
	for (vector<string>::iterator it = options.stdlst.begin();
	     it != options.stdlst.end();
	     ++it) {
	  
	  map<string,Estudiante>::iterator it2 = codEst.find(*it);

	  if (it2 != codEst.end()) {
	    evalStdRepo(it2->first, it2->second, options, evalUnitMidTerm02);
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

int lauchProcess(const string& cmd, vector<string> args, const string& msgError) {

  if (fork() == 0) {
    
    char **cmdArgs = new char*[args.size()+2];

    cmdArgs[0] = createCopyChar(cmd);

    unsigned int i = 1;
    for (; i < args.size(); ++i) {
      cmdArgs[i] = createCopyChar(args[i]);
    }

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

void evalStdRepo(const string& stdId, const Estudiante& stdInfo,
		 const Options2& options, EvalUnit& evalUnit) {
  
   
}

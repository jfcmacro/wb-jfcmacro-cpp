#pragma once
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <unistd.h>
#include <yaml-cpp03/yaml.h>
#include <yaml-cpp03/eventhandler.h>
#include <yaml-cpp03/mark.h>
#include <yaml-cpp03/anchor.h>
#include "stdinfo.h"

using namespace std;

struct Options {
  string workdir;
  string reposdir;
  string timestamp;
  string username;
  vector<string> stdlst;
  bool resumen;
  Options(string& workdir, string& reposdir, string& timestamp,
	  string& username);
  Options();
};

struct Options2 {
  string workdir;
  string reposdir;
  string username;
  vector<string> stdlst;
  bool resumen;
  Options2(string& workdir, string& reposdir, string& username);
  Options2();
};

struct TestForElem {
  string inFile;
  string outFile;
  string cmdToTest;
  string cmdToDiff;
  TestForElem();
  TestForElem(string inFile, string outFile,
	      string cmdToTest, string cmdToDiff);
};

struct ElemToEval {
  string id;
  string name;
  float value;
  string compileCmd;
  vector<string> srcfile;
  /* int nTests; */
  /* TestForElem *tests; */
  vector<TestForElem> tests;
  ElemToEval();
  ElemToEval(string id, string name, float value,
	     string compileCmd);
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
  EvalUnit() :
    evalUnit(""), name(""), workdir(""), nElemsToEval(0), elemsToEval(NULL) { }
};

int remove_directory(const char *path);

void partirLinea(const string& linea, string& codigo,
		 string& nombre, string& email,
		 string& reponame);

void partirEmail(const string& url, string &email, string host);

void createAndCopy(const string& src, char **address);

bool obtenerEstudiantes(map <string,Estudiante>& codEst,
			const char* estudiantesfichero);

int procesarOptiones(Options& options, int argc, char **argv);

int parseOptions2(Options2& options, int argc, char **argv);

EvalUnit* processEvalUnitFile(const char* filename);

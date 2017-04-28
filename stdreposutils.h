/*
 * file: stdreposutils.h
 *
 * created: 2016-05-10
 *
 * programmer: Juan Francisco Cardona McCormick
 *
 * purpose:
 *
 * History of modifications:
 * 2016-06-01 - Start of modifications.
 */
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
/* #include <yaml-cpp03/yaml.h> */
/* #include <yaml-cpp03/eventhandler.h> */
/* #include <yaml-cpp03/mark.h> */
/* #include <yaml-cpp03/anchor.h> */
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/eventhandler.h>
#include <yaml-cpp/mark.h>
#include <yaml-cpp/anchor.h>
#include "stdinfo.h"

using namespace std;

struct Options {
  string workdir;        // Workdir where the repos will be lay down
  string reposdir;       // Name of the repository into Workdir
  string timestamp;      // Time and hour to get the repository
  string reposubdir;     // Subdirectorio belong to the repository
  string username;       // Username to get repositoryw
  vector<string> stdlst; // List of students ids
  bool resumen;          // Enable to show this resumen
  Options(string& workdir, string& reposdir, 
          string& timestamp, string& reposubdir,
          string& username);
  Options();
};

struct Options2 {
  string workdir;          // Workdir where the repos will be lay down
  string reposdir;         // Name of the repository into Workdir
  string evalUnitFile;     // Eval Unit File that describe the compilantio and execution
  vector<string> stdlst;   // Students Ids,
  bool resumen;            // Enable resume
  Options2(string& workdir, string& reposdir, string& evalUnitFile);
  Options2();
};

/*
 * TestForElem
 *
 * Description: This structure describes three posibles programas to test
 * First: Traditional
 * cmdToTest [args] ... < inFile | cmdToDiff - outFile
 * Second: Infile
 * cmdToTest [args] ... inFile | cmdToDiff - outFile
 * Third:
 * cmdToTest [args] ... inFile
 * cmdToTest2 tmpOutFile | cmdToDif - outFile
 */
struct TestForElem {
  string inFile;
  string outFile;
  bool	 redirect;
  string cmdToTest;
  string cmdToDiff;
  string cmdToTest2;
  vector<string> args;
  vector<string> args2;
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
  vector<TestForElem> tests;
  ElemToEval();
  ElemToEval(string id, string name, float value,
	     string compileCmd);
};

struct EvalUnit {
  string evalUnit;
  string name;
  string workdir;
  vector<ElemToEval> elemsToEval;
  EvalUnit();
  EvalUnit(string evalUnit, string name, string workdir);
};

int remove_directory(const char *path);

void partirLinea(const string& linea, string& codigo,
		 string& nombre, string& email,
		 string& reponame);

void partirEmail(const string& url, string &email, string host);

void createAndCopy(const string& src, char **address);

bool obtenerEstudiantes(map <string,Estudiante>& codEst,
			const char* estudiantesfichero);

int procesarOpciones(Options& options, int argc, char **argv);

int parseOptions2(Options2& options, int argc, char **argv);

EvalUnit& processEvalUnitFile(const char* filename);

void printEvalUnit(const EvalUnit& evalUnit, ostream& output);

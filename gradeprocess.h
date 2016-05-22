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

  
int remove_directory(const char *path);

void partirLinea(const string& linea, string& codigo,
		 string& nombre, string& email,
		 string& reponame);

void partirEmail(const string& url, string &email, string host);

void createAndCopy(const string& src, char **address);

bool obtenerEstudiantes(map <string,Estudiante>& codEst,
			const char* estudiantesfichero);

int procesarOptiones(Options& options, int argc, char **argv);

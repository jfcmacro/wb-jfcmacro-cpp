#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include "estudiante.h"
using namespace std;

const string WORKDIR("/home/fcardona/tmp/");
const string REPOSDIR("st0244-2016-1-031");

static void usage(const char* progname) {
  cerr << "Usage: " << progname << " <fichero>" << endl;
  exit(1);
}

void partirLinea(const string& linea, string& codigo,
		 string& nombre, string& email,
		 string& reponame) {

  int sep1 = linea.find("|");
  int sep2 = linea.find("|",sep1+1);
  int sep3 = linea.find("|",sep2+1);
  
  codigo = linea.substr(0,sep1-1);
  nombre = linea.substr(sep1+1, sep2 - (sep1 + 1) );
  email = linea.substr(sep2 + 1, sep3 - (sep2 + 1));
  reponame = linea.substr(sep3 +1);
}

void partirEmail(const string& url, string &email, string host) {
  
  int sep1 = url.find('@');
  email = url.substr(0, sep1-1);
  host = url.substr(sep1+1);
}

int
main(int argc, const char* argv[]) {

  if (argc != 2) {
    usage(argv[0]);
  }
  
  ifstream ifest(argv[1]);

  if (!ifest) {
    cerr << "No puedo abrir fichero de estudiantes" << endl;
    return 1;
  }

  const int MAXBUFFER = 256;
  char buffer[MAXBUFFER];
  map <string,Estudiante> codEst;
  int nEst = 0;
  
  while (ifest.getline(buffer, MAXBUFFER)) {
    string nombre;
    string codigo;
    string email;
    string reponame;
    partirLinea(buffer,codigo,nombre,email,reponame);
    Estudiante e(nombre,codigo,email,reponame);
    codEst[codigo] = e;
    nEst++;
  }

  // chdir();

  // for (map<string,Estudiante>::iterator it = codEst.begin();
  //      it != codEst.end();
  //      ++it) {
  //   cout << "Codigo: " << it->first
  // 	 << " Nombre: " << (it->second).obtenerNombre()
  // 	 << " Reponame: " << (it->second).obtenerRepo()
  // 	 << endl;
  // }

  if (chdir(WORKDIR.c_str()) == 0) {

    struct stat buffer;

    if (stat(REPOSDIR.c_str(),&buffer) != 0) {

      if (mkdir(REPOSDIR.c_str(), 0766) != 0) {
	cerr << "Error: cannot create a file "
	     << errno << endl;
	exit(1);
      }
    }

    if (chdir(REPOSDIR.c_str()) == 0) {
      for (map<string,Estudiante>::iterator it = codEst.begin();
	   it != codEst.end();
	   ++it) {
	// cout << "Codigo: " << it->first
	//      << " Nombre: " << (it->second).obtenerNombre()
	//      << " Reponame: " << (it->second).obtenerRepo()
	//      << endl;
	if (fork() == 0) { /* child */
	  string allname("https://svn.riouxsvn.com/");
	  allname += (it->second).obtenerRepo();
	  execlp("svn", "co", allname.c_str(), (it->second).obtenerEmail(),
		 NULL);
	  cerr << "This cannot happend here" << endl;
	  exit(20);
	}
	int status;
	wait(&status);
	if (WIFEXITED(status)) {
	  if (WEXITSTATUS(status) != 0) {
	    cerr << "Problemas procesando a " << (it->second).obtenerNombre()
		 << endl;
	  }
	}
      }
    }
  }
  else {
    cerr << "WORKDIR: " << WORKDIR << " doesn't exist "
	 << " errno: " << endl;
    exit(1);
  }
  
  return 0;
}

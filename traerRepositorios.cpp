/*
 * fichero: getRepo.cpp
 */
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <sys/wait.h>
// #include <dirent.h>
// #include <time.
#include <unistd.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include "gradeprocess.h"
#include "estudiante.h"

using namespace std;

static void usage(const char* progname) {
  cerr << "Usage: " << progname << endl
       << "[--workdir[=]arg]" << endl
       << "[--reposdir[=]arg]" << endl
       << "[--timestamp[=]arg]" << endl
       << "[--username[=]arg]" << endl
       << "[--stdlist[=]stdcode[,stdcode]..." << endl
       << "[--resumen] <file>" << endl;
  exit(1);
}

void studentProcess(const string& stdId, const Estudiante& stdInfo,
		    const Options& options);

int
main(int argc, char **argv) {

  int iniFich;
  Options options;

  iniFich = procesarOptiones(options, argc, argv);
  
  if (iniFich == argc) {
    usage(argv[0]);
  }

  if (options.resumen) {
    cout << "--workdir: " << options.workdir << endl
	 << "--reposdir: " << options.reposdir << endl
	 << "--timestamp: " << options.timestamp << endl
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

      if (mkdir(options.reposdir.c_str(), 0766) != 0) {
	cerr << "Error: cannot create directory "
	     << options.reposdir
	     << errno << endl;
	exit(1);
      }
    }

    if (chdir(options.reposdir.c_str()) == 0) {

      if (options.stdlst.empty()) {
	
	for (map<string,Estudiante>::iterator it = codEst.begin();
	     it != codEst.end();
	     ++it) {
	  
	  studentProcess(it->first, it->second, options);
	}
      }
      else {
	
	for (vector<string>::iterator it = options.stdlst.begin();
	     it != options.stdlst.end();
	     ++it) {
	  
	  map<string,Estudiante>::iterator it2 = codEst.find(*it);

	  if (it2 != codEst.end()) {
	    studentProcess(it2->first, it2->second, options);
	  }
	  else {
	    cerr << "student id doesn't exists " << *it << endl;
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

void studentProcess(const string& stdId,
		    const Estudiante& stdInfo,
		    const Options& options) {

  string allname("https://svn.riouxsvn.com/");
  allname += stdInfo.obtenerRepo();

  if (fork() == 0) { /* child */

    string svnName("svn");
    string svnCmd("co");
    string svnOptRevision("--revision");
    string svnOptUsername("--username");
	  
    int nArgs = 4;

    if (options.timestamp.size() > 0) nArgs += 2;
    if (options.username.size() > 0) nArgs += 2;

    nArgs++;
	  
    char **args = new char*[nArgs];

    args[0] = new char[svnName.size() + 1];
    ::strcpy(args[0],svnName.c_str());
    args[1] = new char[svnCmd.size() + 1];
    ::strcpy(args[1],svnCmd.c_str());
    args[2] = new char[allname.size() + 1];
    ::strcpy(args[2],allname.c_str());
    args[3] = new char[stdInfo.obtenerEmail().size()];
    ::strcpy(args[3],stdInfo.obtenerEmail().c_str());
	   
    int oai = 4;

    if (options.timestamp.size() > 0) {

      args[oai] = new char[svnOptRevision.size() + 1];
      ::strcpy(args[oai++],svnOptRevision.c_str());
      args[oai] = new char[options.timestamp.size() + 1];
      ::strcpy(args[oai++],options.timestamp.c_str());
    }

    if (options.username.size() > 0) {

      args[oai] = new char[svnOptUsername.size() + 1];
      ::strcpy(args[oai++],svnOptUsername.c_str());
      args[oai] = new char[svnOptUsername.size() + 1];
      ::strcpy(args[oai++],options.username.c_str());
    }

    args[oai] = NULL;

    execvp(args[0], args);
	  
    cerr << "This cannot happen here because: " << errno
	 << " " << strerror(errno) << endl;
    exit(20);
  }
	
  int status;
  wait(&status);
	
  if (WIFEXITED(status)) {
    if (WEXITSTATUS(status) != 0) {
      cerr << "Problemas procesando a"
	   << " codigo: " << stdId 
	   << " nombre: "<< stdInfo.obtenerNombre()
	   << " status: " << WEXITSTATUS(status)
	   << endl
	   << "url: " << allname
	   << " dir: " << stdInfo.obtenerEmail()
	   << endl;
	    
      string svnFile("./");
      svnFile += stdInfo.obtenerEmail();
      if (remove_directory(svnFile.c_str()) != 0) {
	cerr << "Dir: " << svnFile
	     << " no pudo ser removido"
	     << endl;
      }
    }
  } 
}

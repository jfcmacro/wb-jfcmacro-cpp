/*
 * fichero: traerRepositorios.cpp
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <getopt.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <map>
#include "estudiante.h"

using namespace std;

const string WORKDIR = ::getenv("WORKDIR") ?
  ::getenv("WORKDIR")
  : "/home/fcardona/tmp/";
const string REPOSDIR = ::getenv("REPOSDIR") ?
  ::getenv("REPOSDIR")
  : "";
const string TIMESTAMP = ::getenv("TIMESTAMP") ?
  ::getenv("TIMESTAMP")
  : "";
const string USERNAME = ::getenv("SVNUSERNAME") ?
  ::getenv("SVNUSERNAME")
  : "fcardona";

struct Options {
  string workdir;
  string reposdir;
  string timestamp;
  string username;
  bool resumen;
  Options(string& workdir, string& reposdir, string& timestamp,
	  string& username) :
    workdir(workdir), reposdir(reposdir),
    timestamp(timestamp), username(username),
    resumen(false) { }
  Options() :
    workdir(WORKDIR), reposdir(REPOSDIR),
    timestamp(TIMESTAMP), username(USERNAME),
    resumen(false) { }
} options;

int remove_directory(const char *path);

static void usage(const char* progname) {
  cerr << "Usage: " << progname
       << " [--workdir[=]arg] [--reposdir[=]arg] [--timestamp[=]arg] [--username[=]arg] "
       << " [--resumen] <file>" << endl;
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

void createAndCopy(const string& src, char **address) {
  *address = new char[src.size() + 1];
  ::strcpy(*address,src.c_str());
}

int
main(int argc, char **argv) {

  int c;
  int digit_optind = 0;
  
  while(1) {
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    
    static struct option long_options[] = {
      {"workdir",   required_argument, 0, 0},
      {"reposdir",  required_argument, 0, 0},
      {"timestamp", required_argument, 0, 0},
      {"username",  required_argument, 0, 0},
      {"resumen",   no_argument,       0, 0},
      {0,           0,                 0, 0}
    };

    c = getopt_long(argc, argv, "",
		    long_options, &option_index);
    if (c == -1)
      break;
    
    switch (c) {
    case 0:
      switch (option_index) {
      case 0:
	options.workdir = optarg;
	break;

      case 1:
	options.reposdir = optarg;
	break;

      case 2:
	options.timestamp = optarg;
	break;

      case 3:
	options.username = optarg;
	break;

      case 4:
	options.resumen = true;
	break;
      }
      break;
      
    case '?':
      break;
      
    default:
      printf("?? getopt returned character code 0%o ??\n", c);
      break;
    }
  }

  if (optind == argc) {
    usage(argv[0]);
  }

  if (options.resumen) {
    cout << "--workdir: " << options.workdir << endl
	 << "--reposdir: " << options.reposdir << endl
	 << "--timestamp: " << options.timestamp << endl
	 << "--username: " << options.username << endl
	 << "filename: " << argv[optind] << endl;
  }
   
  ifstream ifest(argv[optind]);

  if (!ifest) {
    cerr << "student file input" << argv[optind] << endl;
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
      
      for (map<string,Estudiante>::iterator it = codEst.begin();
	   it != codEst.end();
	   ++it) {

	string allname("https://svn.riouxsvn.com/");
	allname += (it->second).obtenerRepo();

	if (fork() == 0) { /* child */

	  string svnName("svn");
	  string svnCmd("co");
	  string svnOptRevision("--revision");
	  string svnOptUsername("--username");
	  
	  int nArgs = 4;

	  if (options.timestamp.size() > 0) nArgs += 2;
	  if (options.username.size() > 0) nArgs += 2;

	  nArgs++;
	  
	  char **args = new char*[nArgs+1];

	  args[0] = new char[svnName.size() + 1];
	  ::strcpy(args[0],svnName.c_str());
	  args[1] = new char[svnCmd.size() + 1];
	  ::strcpy(args[1],svnCmd.c_str());
	  args[2] = new char[allname.size() + 1];
	  ::strcpy(args[2],allname.c_str());
	  args[3] = new char[(it->second).obtenerEmail().size()];
	  ::strcpy(args[3],(it->second).obtenerEmail().c_str());
	   
	  int oai = 5;

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
	    cerr << "Problemas procesando a "
		 << (it->second).obtenerNombre()
		 << " status: " << WEXITSTATUS(status)
		 << endl
		 << "url: " << allname
		 << " dir: " << (it->second).obtenerEmail()
		 << endl;
	    
	    string svnFile("./");
	    svnFile += (it->second).obtenerEmail();
	    if (remove_directory(svnFile.c_str()) != 0) {
	      cerr << "Dir: " << svnFile
		   << " no pudo ser removido"
		   << endl;
	    }
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

// This was taken from
// url: http://stackoverflow.com/questions/2256945/removing-a-non-empty-directory-programmatically-in-c-or-c
int remove_directory(const char *path)
{
  DIR *d = opendir(path);
  size_t path_len = strlen(path);
  int r = -1;

  if (d)
    {
      struct dirent *p;

      r = 0;

      while (!r && (p=readdir(d)))
	{
	  int r2 = -1;
	  char *buf;
	  size_t len;

	  /* Skip the names "." and ".." as we don't want to recurse on them. */
	  if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
	    {
	      continue;
	    }

	  len = path_len + strlen(p->d_name) + 2;
	  buf = new char[len];

	  if (buf)
	    {
	      struct stat statbuf;

	      snprintf(buf, len, "%s/%s", path, p->d_name);

	      if (!stat(buf, &statbuf))
		{
		  if (S_ISDIR(statbuf.st_mode))
		    {
		      r2 = remove_directory(buf);
		    }
		  else
		    {
		      r2 = unlink(buf);
		    }
		}

	      free(buf);
	    }

	  r = r2;
	}

      closedir(d);
    }

  if (!r)
    {
      r = rmdir(path);
    }

  return r;
}

bool fileExists(const char *path) {

  struct stat buffer;

  if (stat(path,&buffer) != 0) {
    return false;
  }
  
  return S_ISREG(buffer.st_mode) ? true : false;
}


bool isDir(const char *path) {

  struct stat buffer;

  if (stat(path,&buffer) != 0) {
    return false;
  }
  
  return S_ISDIR(buffer.st_mode) ? true : false;
}

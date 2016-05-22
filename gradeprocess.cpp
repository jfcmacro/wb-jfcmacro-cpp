#include "gradeprocess.h"
#include <cstring>
#include <fstream>
#include <getopt.h>

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

bool obtenerEstudiantes(map <string,Estudiante>& codEst,
			const char* estudiantesfichero) {
  
  ifstream ifest(estudiantesfichero);

  if (!ifest) {
    return false;
  }

  const int MAXBUFFER = 256;
  char buffer[MAXBUFFER];
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

  return true;
}

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


Options::Options(string& workdir, string& reposdir, string& timestamp,
	  string& username) :
    workdir(workdir), reposdir(reposdir),
    timestamp(timestamp), username(username),
    resumen(false) { }

Options::Options() :
    workdir(WORKDIR), reposdir(REPOSDIR),
    timestamp(TIMESTAMP), username(USERNAME),
    resumen(false) { }

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

int procesarOptiones(Options& options, int argc, char **argv) {
  int c;
  // int digit_optind = 0;
  
  while(1) {
    // int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    
    static struct option long_options[] = {
      {"workdir",   required_argument, 0, 0},
      {"reposdir",  required_argument, 0, 0},
      {"timestamp", required_argument, 0, 0},
      {"username",  required_argument, 0, 0},
      {"stdlst",    required_argument, 0, 0},
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
	{
	  char *buffer = new char[::strlen(optarg)+1];
	  ::strcpy(buffer,optarg);
	  char *token = ::strtok(buffer, ",");
	  
	  while (token) {
	    string stdId(token);
	    options.stdlst.push_back(stdId);
	    token = ::strtok(NULL,",");
	  }
	  delete[] buffer;
	}

      case 5:
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

  return optind;
}

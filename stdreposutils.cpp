#include "stdreposutils.h"
#include <cstring>
#include <fstream>
#include <getopt.h>

TestForElem::TestForElem() :
  inFile(""), outFile(""),
  cmdToTest(""), cmdToDiff("") { }			     

TestForElem::TestForElem(string inFile, string outFile,
			 string cmdToTest, string cmdToDiff) :
  inFile(inFile), outFile(outFile),
  cmdToTest(cmdToTest), cmdToDiff(cmdToDiff) { }

ElemToEval::ElemToEval() :
  id(""), name(""), value(""),
  compileCmd(compileCmd), srcfile(), tests() { }

ElemToEval::ElemToEval(string id, string name, float value,
		       string compileCmd) :
  id(id), name(name), value(value),
  compileCmd(compileCmd), srcfile(), tests() { }

void partirLinea(const string& linea, string& codigo,
		 string& nombre, string& email,
		 string& reponame) {

  int sep1 = linea.find("|");
  int sep2 = linea.find("|",sep1+1);
  int sep3 = linea.find("|",sep2+1);
  
  codigo = linea.substr(0,sep1);
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

Options2::Options2(string& workdir, string& reposdir,
		   string& username) :
    workdir(workdir), reposdir(reposdir),
    username(username), resumen(false) { }

Options2::Options2() :
    workdir(WORKDIR), reposdir(REPOSDIR),
    username(USERNAME),
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

int parseOptions2(Options2& options, int argc, char **argv) {
  int c;
  // int digit_optind = 0;
  
  while(1) {
    // int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    
    static struct option long_options[] = {
      {"workdir",   required_argument, 0, 0},
      {"reposdir",  required_argument, 0, 0},
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
	options.username = optarg;
	break;

      case 3:
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

class EvalUnitEventHandler : public YAML::EventHandler {
public:
  EvalUnitEventHandler() : currentMap(0), currentSeq(0),
			   key(""), value(""), setKey(false)
  {
    evalUnit = new EvalUnit();
  }
			   
  ~EvalUnitEventHandler() {
  }
  
  void OnDocumentStart(const YAML::Mark& mark) {
    cout << "This documents start on: " << mark.pos
	 << " line: " << mark.line
	 << " col: " << mark.column
	 << endl;
  }
  
  void OnDocumentEnd() {
    cout << "This documents ends" << endl;
  }
  
  void OnNull(const YAML::Mark& mark, YAML::anchor_t anchor) {
    cout << "Null where" << mark.pos
	 << " line: " << mark.line
	 << " col: " << mark.column
	 << endl;
  }
  
  void OnAlias(const YAML::Mark& mark, YAML::anchor_t anchor) {
    cout << "On alias2" << mark.pos
	 << " line: " <<  mark.line
	 << " col: " <<  mark.column
	 << endl;
  }
  
  void OnScalar(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor, const string& value) {
    switch (currentMap) {
    case 1:
      if (!setKey) {
	if (tag == "id" or
	    tag == "name" or
	    tag == "directory" or
	    tag == "elements") {
	  
	  key = tag;
	  setKey = true;
	}
      }
      else {
	if (key == "id") {
	}
      }
      break;
    case 2:
      break;
    case 3:
      break;
    }
    // cout << "scalar: " << mark.pos
    // 	 << " line: " << mark.line
    // 	 << " col: " << mark.column
    // 	 << " tag: " << tag
    // 	 << " value: " << value
    // 	 << endl;
  }
  void OnSequenceStart(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor) {
    cout << "Sequence start: "
	 << mark.pos
	 << " line: " << mark.line
	 << " col: " << mark.column
	 << " tag: " << tag
	 << endl;
  }
  void OnSequenceEnd() {
    cout << "Sequence ends: " << endl;
  }
  void OnMapStart(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor) {
    cout << "Map start: " << mark.pos
	 << " line: " << mark.line
	 << " col: " << mark.column
	 << " tag: " << tag
	 << endl;
    currentMap++;
  }
  void OnMapEnd() {
    cout << "MapEnd" << endl;
    currentMap--;
  }
  EvalUnit* getEvalUnit();
private:
  EvalUnit* evalUnit;
  int currentMap;
  int currentSeq;
  string key;
  string value;
  bool setKey;
};

EvalUnit*
processEvalUnitFile(const char* filename) {

  ifstream infile(filename);

  if (!infile) {
    
    cerr << "Error yaml file: " << filename << endl;
    return NULL;
  } 

  YAML::Parser parse(infile);
  EvalUnitEventHandler evalUnitEventHandler;
  
  if (parse.HandleNextDocument(evalUnitEventHandler)) {
    cout << "Ok" << endl;
  }
  else {
    cout << "Bad" << endl;
  }

  EvalUnit* ret = new EvalUnit();

  // parse.PrintTokens(cout);
  // ret->evalUnit = evalUnit["id"].as<string>();
  // ret->name     = evalUnit["name"].as<string>();
  // ret->workdir  = evalUnit["directory"].as<string>();

  return ret;
}


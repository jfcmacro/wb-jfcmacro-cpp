#include "stdreposutils.h"
#include <cstring>
#include <fstream>
#include <getopt.h>

TestForElem::TestForElem() :
  inFile(), outFile(),
  cmdToTest(), cmdToDiff() { }			     

TestForElem::TestForElem(string inFile, string outFile,
			 string cmdToTest, string cmdToDiff) :
  inFile(inFile), outFile(outFile),
  cmdToTest(cmdToTest), cmdToDiff(cmdToDiff) { }

ElemToEval::ElemToEval() :
  id(), name(), value(),
  compileCmd(), srcfile(), tests() { }

ElemToEval::ElemToEval(string id, string name, float value,
		       string compileCmd) :
  id(id), name(name), value(value),
  compileCmd(compileCmd), srcfile(), tests() { }

EvalUnit::EvalUnit() :
  evalUnit(), name(), workdir(),
  elemsToEval() { } 

EvalUnit::EvalUnit(string evalUnit, string name, string workdir) : 
  evalUnit(evalUnit), name(name),
  workdir(workdir), elemsToEval() { }

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
		   string& username, string& evalUnitFile)
  :
  workdir(workdir), reposdir(reposdir),
  username(username), evalUnitFile(evalUnitFile),
  resumen(false) { }

Options2::Options2() :
    workdir(WORKDIR), reposdir(REPOSDIR),
    username(USERNAME), evalUnitFile(),
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
      {"workdir",      required_argument, 0, 0},
      {"reposdir",     required_argument, 0, 0},
      {"username",     required_argument, 0, 0},
      {"evalunitfile", required_argument, 0, 0},
      {"stdlst",       required_argument, 0, 0},
      {"resumen",      no_argument,       0, 0},
      {0,              0,                 0, 0}
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
	options.evalUnitFile = optarg;
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
	break;

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
  EvalUnitEventHandler() : testForElem(0),
			   elemToEval(0),
			   evalUnit(),
			   currentMap(0),
			   currentSeq(0),
			   key(),
			   // value(),
			   setKey(false) {
    testForElem = new TestForElem();
    elemToEval = new ElemToEval();
  }
			   
  ~EvalUnitEventHandler() { }
  
  void OnDocumentStart(const YAML::Mark& mark) {
    // cout << "This documents start on: " << mark.pos
    // 	 << " line: " << mark.line
    // 	 << " col: " << mark.column
    // 	 << endl;
  }
  
  void OnDocumentEnd() {
    // cout << "This documents ends" << endl;
  }
  
  void OnNull(const YAML::Mark& mark, YAML::anchor_t anchor) {
    // cout << "Null where" << mark.pos
    // 	 << " line: " << mark.line
    // 	 << " col: " << mark.column
    // 	 << endl;
  }
  
  void OnAlias(const YAML::Mark& mark, YAML::anchor_t anchor) {
    // cout << "On alias2" << mark.pos
    // 	 << " line: " <<  mark.line
    // 	 << " col: " <<  mark.column
    // 	 << endl;
  }
  
  void OnScalar(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor, const string& value) {
    
    switch (currentMap) {
    case 1:
      if (!setKey) {
	if (value == "id" or
	    value == "name" or
	    value == "directory") {
	  
	  key = value;
	  setKey = true;
	}
	else if (value == "elements") { // Next event is start sequence
	}
	else {
	  cerr << "key doesnt' found: " << value << endl;
	}
      }
      else {
	if (key == "id") {
	  
	  evalUnit.evalUnit = value;
	  setKey = false;
	}
	else if (key == "name") {
	  
	  evalUnit.name = value;
	  setKey = false;
	}
	else if (key == "directory") {
	  
	  evalUnit.workdir = value;
	  setKey = false;
	}
	
	setKey = false;
	key = "";
      }
      break;
    case 2:
      if (!setKey) {
	if (value == "id" or
	    value == "name" or
	    value == "value" or
	    value == "compile") {
	  key = value;
	  setKey = true;
	}
	else if (value == "srcfile") { // Next event is start sequence
	  key = value;
	  setKey = true;
	}
	else if (value == "test") { // Next event is start sequence
	}
	else {
	  cerr << "Unknow key " << value << " " << currentMap << endl;
	}
      }
      else {
	if (key == "id") {
	  
	  elemToEval->id = value;
	  setKey = false;
	}
	else if (key == "name") {
	  
	  elemToEval->name = value;
	  setKey = false;
	}
	else if (key == "value") {
	  
	  istringstream iss(value);
	  iss >> elemToEval->value;
	  setKey = false;
	}
	else if (key == "srcfile") {
	  
	  elemToEval->srcfile.push_back(value);
	  // setKey = false;
	}
	else if (key == "compile") {
	  
	  elemToEval->compileCmd = value;
	  setKey = false;
	}
	else {
	  setKey = false;
	}
      }
      break;
    case 3:
      if (!setKey) {
	
	if (value == "infile" or
	    value == "outfile" or
	    value == "command" or
	    value == "diff") {
	  
	  key = value;
	  setKey = true;
	}
	else {
	  cerr << "Unknown key: " << value << endl;
	}
      }
      else {
	if (key == "infile") {
	  
	  testForElem->inFile = value;
	  setKey = false;
	}
	else if (key == "outfile") {
	  
	  testForElem->outFile = value;
	  setKey = false;
	}
	else if (key == "command") {
	  
	  testForElem->cmdToTest = value;
	  setKey = false;
	}
	else if (key == "diff") {
	  
	  testForElem->cmdToDiff = value;
	  setKey = false;
	}
	else {
	  
	  setKey = false;
	  key = "";
	}
      }
      
      break;
    }
  }
  
  void OnSequenceStart(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor) {

  }
  
  void OnSequenceEnd() {
    setKey = false;
  }
  
  void OnMapStart(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor) {
    
    currentMap++;
  }
  
  void OnMapEnd() {

    switch(currentMap) {
    case 1:
      
      break;
    case 2:
      
      evalUnit.elemsToEval.push_back(*elemToEval);
      elemToEval = new ElemToEval();
      break;
    case 3:
      
      elemToEval->tests.push_back(*testForElem);
      testForElem = new TestForElem();
      
      break;
    }
    
    currentMap--;
  }
  
  EvalUnit& getEvalUnit() {
    EvalUnit* p = new EvalUnit(evalUnit);
    return *p;
  }
  
private:
  TestForElem *testForElem;
  ElemToEval *elemToEval;
  EvalUnit evalUnit;
  int currentMap;
  int currentSeq;
  string key;
  // string value;
  bool setKey;
  enum { NO_SEQ, SEQ_ELEMTOEVAL, SEQ_TESTFORELEM } currSeq;
};
    
EvalUnit&
processEvalUnitFile(const char* filename) {

  ifstream infile(filename);

  // TODO: Find another way to manage this possible error
  // if (!infile) {
    
  //   cerr << "Error yaml file: " << filename << endl;
    
  // }
  
  YAML::Parser parse(infile);
  EvalUnitEventHandler evalUnitEventHandler;
  
  if (parse.HandleNextDocument(evalUnitEventHandler)) {
    cout << "Ok" << endl;
  }
  else {
    cout << "Bad" << endl;
  }
  
  
  
  // parse.PrintTokens(cout);
  // ret->evalUnit = evalUnit["id"].as<string>();
  // ret->name     = evalUnit["name"].as<string>();
  // ret->workdir  = evalUnit["directory"].as<string>();
  
  return evalUnitEventHandler.getEvalUnit();
}
 
void
printEvalUnit(const EvalUnit& evalUnit, ostream& output) {

  output << "EvalUnit: " << evalUnit.evalUnit << endl
	 << "name: " << evalUnit.name << endl
	 << "workdir: " << evalUnit.workdir << endl
	 << "elements to eval: " << endl;
  for (unsigned i = 0; i < evalUnit.elemsToEval.size(); ++i) {
    output << "id: " << evalUnit.elemsToEval[i].id << endl
	   << "name: " << evalUnit.elemsToEval[i].name << endl
	   << "value: " << evalUnit.elemsToEval[i].value << endl
	   << "compileCmd: " << evalUnit.elemsToEval[i].compileCmd << endl
	   << "srcfiles: ";
    for (unsigned j = 0; j < evalUnit.elemsToEval[i].srcfile.size(); ++j) {
      output << evalUnit.elemsToEval[i].srcfile[j];
      if (j + 1 != evalUnit.elemsToEval[i].srcfile.size())
	output << ", ";
    }
    output << endl << "tests:" << endl;
    for (unsigned j = 0; j < evalUnit.elemsToEval[i].tests.size(); ++j) {
      output << "inFile:" << evalUnit.elemsToEval[i].tests[j].inFile
	     << " outFile: " << evalUnit.elemsToEval[i].tests[j].outFile
	     << " cmdToTest: " << evalUnit.elemsToEval[i].tests[j].cmdToTest
	     << " cmdToDiff: " << evalUnit.elemsToEval[i].tests[j].cmdToDiff
	     << endl;
    }
  }
}

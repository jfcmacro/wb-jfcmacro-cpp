/*
 * file: stdreposutils.cpp
 *
 * created: 2016-05-10
 *
 * programmer: Juan Francisco Cardona McCormick
 *
 * purpose:
 *
 * History of modifications:
 * 2017-03-22 - Updating options
 * 2016-06-01 - Start of modifications.
 */
#include "stdreposutils.h"
#include <cstring>
#include <fstream>
#include <getopt.h>
#include <stack>
#include <iostream>

TestForElem::TestForElem() :
  inFile(), outFile(), redirect(true),
  cmdToTest(), cmdToDiff(), cmdToTest2(), args() { }

TestForElem::TestForElem(string inFile, string outFile,
                         string cmdToTest, string cmdToDiff) :
  inFile(inFile), outFile(outFile), redirect(true),
  cmdToTest(cmdToTest), cmdToDiff(cmdToDiff), cmdToTest2(), args() { }

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
const string REPOSUBDIR = ::getenv("REPOSUBDIR") ?
  ::getenv("REPOSUBDIR")
  : "";

Options::Options(string& workdir, string& reposdir,
                 string& timestamp, string& reposubdir,
                 string& username) :
  workdir(workdir),
  reposdir(reposdir),
  timestamp(timestamp),
  reposubdir(reposubdir),
  username(username),
  resumen(false) { }

Options::Options() :
    workdir(WORKDIR), reposdir(REPOSDIR),
    timestamp(TIMESTAMP), reposubdir(REPOSUBDIR),
    username(USERNAME),
    resumen(false) { }

Options2::Options2(string& workdir, string& reposdir,
                   string& evalUnitFile)
  :
  workdir(workdir), reposdir(reposdir),
  evalUnitFile(evalUnitFile),
  resumen(false) { }

Options2::Options2() :
    workdir(WORKDIR), reposdir(REPOSDIR),
    evalUnitFile(),
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

int procesarOpciones(Options& options, int argc, char **argv) {
  int c;
  // int digit_optind = 0;

  while(1) {
    // int this_option_optind = optind ? optind : 1;
    int option_index = 0;

    static struct option long_options[] = {
      {"workdir",    required_argument, 0, 0},
      {"reposdir",   required_argument, 0, 0},
      {"timestamp",  required_argument, 0, 0},
      {"username",   required_argument, 0, 0},
      {"stdlst",     required_argument, 0, 0},
      {"resumen",    no_argument,       0, 0},
      {"reposubdir", required_argument, 0, 0},
      {0,            0,                 0, 0}
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

      case 6:
        options.reposubdir = optarg;
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
        options.evalUnitFile = optarg;
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

  return optind;
}

class EvalUnitEventHandler : public YAML::EventHandler {
public:
  EvalUnitEventHandler() : testForElem(0),
                           elemToEval(0),
                           evalUnit(),
                           currentMap(0),
                           currentSeq(0),
                           keys() {
    testForElem = new TestForElem();
    elemToEval = new ElemToEval();
  }

  ~EvalUnitEventHandler() { }

  void OnDocumentStart(const YAML::Mark& mark) { }

  void OnDocumentEnd() { }

  void OnNull(const YAML::Mark& mark, YAML::anchor_t anchor) { }

  void OnAlias(const YAML::Mark& mark, YAML::anchor_t anchor) { }

  void OnScalar(const YAML::Mark& mark, const string& tag,
                YAML::anchor_t anchor,  const string& value) {

    switch (currentMap) {
    case 1:
      if (keys.size() == 0) {
        if (value == "id" or value == "name" or
            value == "directory" or value == "elements") {

          keys.push(value);
        }
        else {
          cerr << "key doesnt' found: " << value << endl;
          ::_exit(1);
        }
      }
      else {

        if (keys.top() == "id") {

          evalUnit.evalUnit = value;
          keys.pop();
        }
        else if (keys.top() == "name") {

          evalUnit.name = value;
          keys.pop();
        }
        else if (keys.top() == "directory") {

          evalUnit.workdir = value;
          keys.pop();
        }
        else if (keys.top() == "elements") {
        }
        else {
          cerr << "Unknown key stored" << keys.top() << endl;
          ::_exit(1);
        }
      }
      break;

    case 2:
      if (keys.size() == 1) {
        if (value == "id" or value == "name" or
            value == "value" or value == "compile" or
            value == "srcfile" or value == "tests") {

          keys.push(value);
        }
        else {

          cerr << "Unknown key " << value << "at: "
               << currentMap
               << "stack top: " << keys.top()
               << endl;
          ::_exit(1);
        }
      }
      else if (keys.size() == 2) {

        if (keys.top() == "id") {

          elemToEval->id = value;
          keys.pop();
        }
        else if (keys.top() == "name") {

          elemToEval->name = value;
          keys.pop();
        }
        else if (keys.top() == "value") {

          istringstream iss(value);
          iss >> elemToEval->value;
          keys.pop();
        }
        else if (keys.top() == "srcfile") {

          elemToEval->srcfile.push_back(value);
        }
        else if (keys.top() == "compile") {

          elemToEval->compileCmd = value;
          keys.pop();
        }
        else if (keys.top() == "tests") {
        }
        else {
          cerr << "Unknown key stored" << keys.top() << endl;
          ::_exit(1);
        }
      }
      else {
        cout << "stack size() " << keys.size()
             << " is incompatible with map level: "
             << currentMap
             << endl;
        ::_exit(1);
      }
      break;

    case 3:
      if (keys.size() == 2) {

        if (value == "infile" or
            value == "outfile" or
            value == "command" or
            value == "diff" or
            value == "command2" or
            value == "redirect" or
            value == "args" or
            value == "args2") {

          keys.push(value);
        }
        else {
          cerr << "Unknown key " << value << "at: "
               << currentMap
               << "stack top: " << keys.top()
               <<endl;
          ::_exit(1);
        }
      }
      else if (keys.size() == 3) {
        if (keys.top() == "infile") {

          testForElem->inFile = value;
          keys.pop();
        }
        else if (keys.top() == "outfile") {

          testForElem->outFile = value;
          keys.pop();
        }
        else if (keys.top() == "command") {

          testForElem->cmdToTest = value;
          keys.pop();
        }
        else if (keys.top() == "diff") {

          testForElem->cmdToDiff = value;
          keys.pop();
        }
        else if (keys.top() == "command2") {

          testForElem->cmdToTest2 = value;
          keys.pop();
        }
        else if (keys.top() == "redirect") {

          testForElem->redirect = value == "true" ? true : false;
          keys.pop();
        }
        else if (keys.top() == "args") {

          testForElem->args.push_back(value);
        }
        else if (keys.top() == "args2") {

          testForElem->args2.push_back(value);
        }
        else {
          cerr << "Unknown key stored" << keys.top() << endl;
          ::_exit(1);
        }
      }
      else {
        cout << "stack size() " << keys.size()
             << " is incompatible with map level: "
             << currentMap
             << endl;
        ::_exit(1);
      }
      break;
    }
  }

  void OnSequenceStart(const YAML::Mark& mark, const string& tag, YAML::anchor_t anchor) {

  }

  void OnSequenceEnd() {
    switch(currentMap) {
    case 1:
      if (keys.top() == "elements") {
        keys.pop();
      }
      else {
        cerr << "Unknown key stored" << keys.top() << endl;
        ::_exit(1);
      }
      break;

    case 2:
      if (keys.top() == "srcfile") {

        keys.pop();
      }
      else if (keys.top() == "tests") {

        keys.pop();
      }
      else {
        cerr << "Unknown key stored" << keys.top() << endl;
        ::_exit(1);
      }
      break;

    case 3:
      if (keys.top() == "args" or
          keys.top() == "args2") {

        keys.pop();
      }
      else {
        cerr << "Unknown key stored" << keys.top() << endl;
        ::_exit(1);
      }
      break;
    }
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
  stack<string> keys;
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

      output << "inFile: " << evalUnit.elemsToEval[i].tests[j].inFile
             << " outFile: " << evalUnit.elemsToEval[i].tests[j].outFile
             << " redirect: " << evalUnit.elemsToEval[i].tests[j].redirect
             << " cmdToTest: " << evalUnit.elemsToEval[i].tests[j].cmdToTest
             << " cmdToDiff: " << evalUnit.elemsToEval[i].tests[j].cmdToDiff
             << " cmdToTest2: " << evalUnit.elemsToEval[i].tests[j].cmdToTest2
             << " args: ";

      for (unsigned k = 0; k < evalUnit.elemsToEval[i].tests[j].args.size(); ++k) {
        cout << evalUnit.elemsToEval[i].tests[j].args[k];
        if (k + 1 != evalUnit.elemsToEval[i].tests[j].args.size()) {
          cout << ", ";
        }
      }

      cout << endl;
    }
  }
}

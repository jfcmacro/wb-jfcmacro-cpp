#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "process.h"

using namespace std;

static void usage(const char *progname) {
  cerr << "Usage: " << progname << " <fichero> " << endl;
  exit(1);
}

const char * defaultAWKFile = "../awk/procesarSirenaMosaico.awk";

int
main(int argc, const char* argv[]) {

  if (argc != 2) {
    usage(argv[0]);
  }

  const char *dirAWKUtil = ::getenv("EAFIT_AWK_MOSAICO");

  dirAWKUtil = dirAWKUtil ? dirAWKUtil : defaultAWKFile;

  
  struct stat dirStatInfo;
  if (::stat(defaultAWKFile, &dirStatInfo) == 0) {
    if (!S_ISREG(dirStatInfo.st_mode)) {
      cerr << " awk file: " << defaultAWKFile
           << " isn't a regular file " << endl;
      exit(1);
    }
  }
  else {
    cerr << "awk file: " << defaultAWKFile
         << " could not be stated errno: " << errno << endl;
      exit(1);
  }

  string cmdOne("xclip");
  vector<string> argsOne;
  argsOne.push_back("-selection");
  argsOne.push_back("c");
  argsOne.push_back("-o");

  string cmdTwo("awk");
  vector<string> argsTwo;
  argsTwo.push_back("-f");
  argsTwo.push_back(defaultAWKFile);

  string cmdThree("./eafitCVSInfo2StdInfo");
  vector<string> argsThree;
  
  return 0;
}

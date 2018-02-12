#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <error.h>
#include <cstring>
#include <iostream>
#include <sstream>

int
main(void) {
  struct stat bStat;
  std::ostringstream os;
  os << "/proc/" << ::getpid() << "/exe";
  std::cout << os.str() << std::endl;

  if (lstat(os.str().c_str(), &bStat) == -1) {
    std::cerr << "Error: " << strerror(errno) << std::endl;
    return 1;
  }

  if (S_ISLNK(bStat.st_mode)) {

    char *realfilename = new char[1024];
    readlink(os.str().c_str(), realfilename, 1024);

    std::string dir(realfilename);

    delete[] realfilename;

    dir = dir.substr(0, dir.rfind("/")); 
    std::cout << dir << std::endl;
  }
  
  return 0;
}

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cerrno>
#include <cstdlib>
#include <iostream>

static
void usage(const char* progname) {
  std::cerr << "Usage: " << progname << " filename ..." << std::endl;
  ::exit(1);
}

int
main(int argc, char *argv[]) {

  if (argc == 1) {
    usage(argv[0]);
  }

  for (int i = 1; i < argc; ++i) {
    struct stat sb;

    if (stat(argv[i], &sb) != 0) {
      switch(errno) {
      case EACCES:
        std::cerr << "filename: " << argv[i]
                  << " not valid permissions" << std::endl;
        break;
      case ENOENT:
        std::cerr << "filename: " << argv[i]
                  << " pathname doesn't exist " << std::endl;
        break;
      case ENOTDIR:
        std::cerr << "filename: " << argv[i]
                  << " a path is invalid " << std::endl;
        break;
      }
    }
    else {
      std::cout << "filename: " << argv[i];
      if (S_ISREG(sb.st_mode)) std::cout << " is a regular file";
      if (S_ISDIR(sb.st_mode)) std::cout << " is a directory";
      if (S_ISCHR(sb.st_mode)) std::cout << " is a character device";
      if (S_ISBLK(sb.st_mode)) std::cout << " is a block device";
      if (S_ISFIFO(sb.st_mode)) std::cout << " is a named pipe";
      if (S_ISLNK(sb.st_mode)) std::cout << " is a symbolic link";
      if (S_ISSOCK(sb.st_mode)) std::cout << " is a socket";
      std::cout << std::endl;
    }
  }
  
  return 0;
}

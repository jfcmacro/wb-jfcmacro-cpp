#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include <errno.h>
#include <unistd.h>

using namespace std;

void
printDevice(dev_t dev) {
  cerr << "Device: " << dev << endl;
}

void
testSTMODE(mode_t mode) {
  if (mode & S_IFSOCK) {
    cerr << "It is a socket" << endl;
  }
  if (mode & S_IFLNK) {
    cerr << "It is a symbolic link" << endl;
  }
  if (mode & S_IFREG) {
    cerr << "It is a regular file" << endl;
  }
  if (mode & S_IFBLK) {
    cerr << "It is a regular file" << endl;
  }
  if (mode & S_IFDIR) {
    cerr << "It is a directory" << endl;
  }
  if (mode & S_IFCHR) {
    cerr << "It is a character file" << endl;
  }
  if (mode & S_IFIFO) {
    cerr << "It is a fifo" << endl;
  }
}

int
main(int argc, char *argv[]) {

  struct stat inStat;
  struct stat outStat;

  if (argc > 1) {
    cerr << argv[1] << endl;
  }
  
  if (fstat(0, &inStat) == -1) {
    cerr << "in error: " << strerror(errno) << endl;
  }
  
  testSTMODE(inStat.st_mode);
  printDevice(inStat.st_dev);

  if (fstat(1, &outStat) == -1) {
    cerr << "out error: " << strerror(errno) << endl;
  }

  testSTMODE(outStat.st_mode);
  printDevice(outStat.st_dev);

  char c;
  int nrc;

  while ((nrc = read(0, &c, 1)) > 0) {
    cout << c;
  }

  if (nrc == -1) {
    cerr << "Error: " << strerror(errno) << endl;
  }

  return 0;
}

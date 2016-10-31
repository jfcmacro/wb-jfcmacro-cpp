#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <errno.h>

using namespace std;

static void usage(const char *progname) {
  cerr << "Usage: " << progname << " <shmid> " << endl;
  _exit(1);
}
const size_t MAX = 2048;

int
main(int argc, char *argv[]) {

  if (argc != 2) {
    usage(argv[0]);
  }
  
  key_t key = atoi(argv[1]);

  if (shmget(key, MAX, IPC_CREAT | IPC_EXCL | 0660 ) == -1) {
    cerr << "Fail due: " << strerror(errno) << endl;
    _exit(1);
  }

  return 0;
}

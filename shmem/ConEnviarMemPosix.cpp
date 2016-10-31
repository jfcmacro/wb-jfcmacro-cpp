#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <errno.h>
#include <sys/types.h>
#include "mensaje.h"

using namespace std;

static void usage(const char *progname) {
  cerr << "Usage: " << progname << " <shmid> mensaje{1,5}" << endl;
  _exit(1);
}
const size_t MAX = 2048;

int
main(int argc, char *argv[]) {

  if (argc < 2 or argc >= 8) {
    usage(argv[0]);
  }
  
  int fd;

  if ((fd = shm_open(argv[1], O_RDWR, 0660)) == -1) {
    cerr << "Fail due: " << strerror(errno) << endl;
    _exit(1);
  }

  int nMsg = argc - 2;

  void *start = mmap(NULL, MAX, PROT_READ | PROT_WRITE, MAP_SHARED,
                     fd, 0);

  if (start == (void *) -1) {
    cerr << "Fail due: " << strerror(errno) << endl;
    _exit(1);
  }

  int *nMem = static_cast<int*>(start);

  *nMem = nMsg;

  char *Mensajes = (char *)(nMem + sizeof(int));

  for (int i = 0; i < nMsg; ++i) {
    strcpy(Mensajes, argv[i + 2]);
    Mensajes = Mensajes + TAMMEN;
  }

  munmap(start, MAX);

  close(fd);
  
  return 0;
}

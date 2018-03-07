#include <cstdlib>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

void*
threadnado(void *) {

  for (;;) {
    std::cout << "I'm the walrus " << ::pthread_self()
              << " and my daddy is " << ::getpid()
              << std::endl;
    ::sleep(1);
  }

  return nullptr;
}


int
main() {
  pthread_t myThread;

  pthread_create(&myThread, NULL, threadnado, NULL);

  fork();

  int *p;

  pthread_join(myThread, (void **) &p);

  return 0;
}


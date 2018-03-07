#include <iostream>
#include <cstdlib>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int *glob_var;

int main(void)
{
  glob_var = static_cast<int*>(::mmap(NULL, sizeof *glob_var,
                                      PROT_READ | PROT_WRITE, 
                                      MAP_SHARED | MAP_ANONYMOUS, -1, 0));

  *glob_var = 1;

  if (fork() == 0) {
    *glob_var = 5;
    exit(EXIT_SUCCESS);
  } else {
    wait(NULL);
    sleep(10);
    std::cout << *glob_var << std::endl;
    munmap(glob_var, sizeof *glob_var);
  }
 
  return EXIT_SUCCESS;
}

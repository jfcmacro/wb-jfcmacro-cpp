#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

int
main() {

  int i;
  std::cin >> i;
  std::string semname = "semaforo";
  sem_t **arraySem = new sem_t*[i];

  for (int j = 0; j < i; j++) {
    std::ostringstream name;
    name << semname << j;
    std::string realName(name.str());
    
    arraySem[j] = sem_open(realName.c_str(),
			   O_CREAT | O_EXCL , 0660, 1);

    if (arraySem[j] == SEM_FAILED) {
      std::cerr << "Error" << std::endl;
    }
  }

  return EXIT_SUCCESS;
}

#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <string>

void launch_process_wait(std::string, 


int
main(int argc, char *argv) {

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " nwdir" << std::endl;
    ::exit(FAILURE_PROCESS);
  }

  
}

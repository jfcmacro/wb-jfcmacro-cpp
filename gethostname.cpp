#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

int
main(void) {

  const int BUFFER_SIZE = 256;
  char hostname[BUFFER_SIZE];

  if (::gethostname(hostname, BUFFER_SIZE) == -1) {
    perror("gethostname");
    return EXIT_FAILURE;
  }

  std::cout << "Hostname: " << hostname << std::endl;
  std::cout << "Host id: " << (unsigned long) gethostid() << std::endl;

  struct hostent *pHostEntry;

  if ((pHostEntry = ::gethostbyname(hostname)) == nullptr) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  std::cout << "Oficial hostname: " << pHostEntry->h_name << std::endl;

  for (int i = 0; pHostEntry->h_aliases[i]; i++) {
    std::cout << "aka name: " << pHostEntry->h_aliases[i] << std::endl;
  }

  std::cout << "Address type: " << pHostEntry->h_addrtype << std::endl;

  for (char **p = pHostEntry->h_addr_list; *p; p++) {
    std::cout << "address: " << *p << std::endl;
  }
  return EXIT_SUCCESS;
}

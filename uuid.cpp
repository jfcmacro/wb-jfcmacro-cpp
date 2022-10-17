/*
 * compiling
 * $ g++ -c uuid.cpp
 * $ g++ -o uuid uuid.o -lossp-uuid++
 *
 * o
 *
 * $ make -k -f makeuuid.mk
 */
#include <iostream>
#include <uuid++.hh>
#include <cstdlib>

char *uuid_v1(void) {
  uuid id;
  char *str;

  id.make(UUID_MAKE_V1);
  str = id.string();
  return str;
}

/* generate a DCE 1.1 v3 UUID from an URL */
char *uuid_v3(const char *url) {
  uuid id;
  uuid id_ns;
  char *str;

  id_ns.load("ns:URL");
  id.make(UUID_MAKE_V3, &id_ns, url);
  str = id.string();
  return str;
}

int
main(int argc, char *argv[]) {

  std::cout << uuid_v1() << std::endl;
  std::cout << uuid_v1() << std::endl;
  std::cout << uuid_v1() << std::endl;
  std::cout << uuid_v1() << std::endl;

  std::cout << uuid_v3("http://www.s4n.com") << std::endl;
  std::cout << uuid_v3("http://www.s4n.com") << std::endl;

  return EXIT_SUCCESS;
}

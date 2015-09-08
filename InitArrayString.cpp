#include <iostream>

int
main(void) {

  char nombre[] { "Juan" };
  const char *values[] { "uno" , "dos" };
  register int value { 1000 };
  auto det { 123.34 };
  
  std::cout << nombre << std::endl;
  std::cout << values[0] << std::endl;
  std::cout << values[1] << std::endl;

  return 0;
}

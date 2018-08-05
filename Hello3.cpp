#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int
main(void) {
  char hello[] = "Hola\n";
  char hello2[] = "\110\157\154\141\40\12";
  char hello3[] = "\x48\x6F\x6C\x61\x20\x0A";
  char car[] = "\a\b\f\n\r\t\v";
  
  cout << hello;
  cout << hello2;
  cout << hello3;
  cout << car;

  return EXIT_SUCCESS;
}

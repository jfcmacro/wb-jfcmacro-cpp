#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <map>

int genNum(int min, int max);
char numToTest(int value);

int
main(int argc, char *argv[]) {

  ::srand(time(NULL));

  for (int i = 0; i < 20; ++i) {
    int bandeja = genNum(0,4);
    char test = numToTest(genNum(1,3));
    int nTest = genNum(1,5);
    std::cout << bandeja << ' '
	      << test << ' '
	      << nTest << std::endl;
  }
  return EXIT_SUCCESS;
}

int genNum(int limInf, int limSup) {
  return (::rand() % (limSup - limInf + 1)) + limInf;
}

char numToTest(int value) {
  char c = '\0';

  switch (value) {
  case 0:
    c = 'B';
    break;
  case 1:
    c = 'D';
    break;
  case 2:
    c = 'S';
    break;
  default:
    c = 'B';
    break;
  }

  return c;
}

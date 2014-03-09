#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int
main() {
  printf("%p\n", malloc(sizeof(int)));
  printf("%p\n", new int[1]); 
  return 0;
}

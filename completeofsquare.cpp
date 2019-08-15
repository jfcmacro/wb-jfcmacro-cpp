#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void printHash(int n);

int
main() {
  const int N = 5;
  for (int i = 0; i < N; i++)
    printHash(N);
  return EXIT_SUCCESS;
}

void printHash(int n) {
  for (int i = 0; i < n; i++)
    cout << "#";
  cout << endl;
}



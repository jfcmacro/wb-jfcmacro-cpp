#include <iostream>
#include <cstdlib>

const int N = 100000;

int
main(int argc, char *argv[]) {
  int n;
  std::cin >> n; 
  int i, j, a[n+1];

  for (a[1] = 0, i = 2; i <= n; i++) a[i] = 1;

  for (i = 2; i <= n/2; i++)
    for (j = 2; j <= n/i; j++)
      a[i*j] = 0;

  for (i = 1; i <= n; i++)
    if (a[i]) std::cout << i << ' ';

  std::cout << std::endl;

  return EXIT_SUCCESS;
}

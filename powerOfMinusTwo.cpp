#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
  const int N = 10;
  const int FIVE = 5;
  const char C_FIVE = '5';
  int d[N];

  int r;
  for (int k = 0; k < N; k++) {
    std::cout << "."; r = 0;
    for (int i = 0; i <= k - 1; i++) {
      r = 10 * r + d[i]; d[i] = r / 2;
      r = r - 2 * d[i];
      std::cout << static_cast<char>(d[i] + '0');
    }
    d[k] = FIVE;
    std::cout << C_FIVE << std::endl;
  }

  return EXIT_SUCCESS;
}

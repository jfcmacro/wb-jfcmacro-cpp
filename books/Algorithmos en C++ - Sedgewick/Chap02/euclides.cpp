#include "euclides.h"

void
swap(int& x, int& y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int
mcd(int u, int v) {

  while (u > 0) {
    if (u < v)
      swap(u, v);
    u = u - v;
  }
  return v;
}


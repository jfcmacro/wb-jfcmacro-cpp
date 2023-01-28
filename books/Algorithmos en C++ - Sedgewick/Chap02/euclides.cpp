#include "euclides.h"

void
swap(int& x, int& y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int
mcd(int u, int v, bool mod, std::function<void(int,int)> fun) {

  while (u > 0) {
    fun(u,v);
    if (u < v)
      swap(u, v);
    fun(u,v);
    u = mod ? u % v : u - v;
    fun(u,v);
  }
  return v;
}

int
mcd(int u, int v) {
  return mcd(u, v, false, [](int a, int b) -> void { return; });
}

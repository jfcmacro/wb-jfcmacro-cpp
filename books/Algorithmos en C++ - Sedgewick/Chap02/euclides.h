#pragma once
#include <functional>

int mcd(int u, int v);
int mcd(int u, int v, bool mod, std::function<void(int,int)> func);

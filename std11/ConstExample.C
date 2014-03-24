#include <iostream>
#include <vector>

using namespace std;

constexpr double square(double x);

constexpr double square(double x) {
  return x * x;
}

const int dmv = 17;

int var = 17;

constexpr double max1 = 1.4*square(dmv);

// constexpr double max2 = 1.4*square(var);

const double max3 = 1.4*square(var);

double sum(const vector<double>&);

vector<double> v { 1.2, 3.4, 4.5 };

const double s1 = sum(v);

// constexpr doble s2 = sum(v);


int
main() {

  return 0;
}


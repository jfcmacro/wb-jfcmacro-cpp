#include <iostream>

namespace MiEspacio {
  class MiClase {
  public:
    void m1();
    int a;
  };
}

namespace MiOtroEspacio {
  class MiClase {
  public:
    void m1();
    float a;
  };
}

int
main() {
  MiEspacio::MiClase m1;
  MiOtroEspacio::MiClase m2;

  m1.m1();
  m2.m1();
  
  return 0;
}

void
MiEspacio::MiClase::m1() {
}

void
MiOtroEspacio::MiClase::m1() {
}

#include <iostream>
#include <cstdlib>

class Nada {
public:
  Nada(int v);
  bool operator==(Nada& t);
  bool operator!=(Nada& t);
private:
  int v;
};


Nada::Nada(int v) : v(v) { }

bool Nada::operator==(Nada& t) {
  return this->v == t.v;
}

bool Nada::operator!=(Nada& t) {
  return this->v != t.v;
}

int
main(void) {

  Nada a(1), b(2), c(1);

  if (a != b) std::cout << "Diferentes" << std::endl;

  if (a == c) std::cout << "Iguales" << std::endl;

  Nada& ra = a;
  Nada& rc = c;

  if (ra == rc) std::cout << "Iguales?" << std::endl;

  return EXIT_SUCCESS;
  
}

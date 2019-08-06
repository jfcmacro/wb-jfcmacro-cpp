#include <iostream>
#include <cstdlib>

void hacerPrimera();
void hacerSegunda();
void hacerTercera();
void hacerNada();

int
main(void) {

  enum Opciones { Primera, Segunda, Tercera };

  Opciones opcion;

  int i;

  std::cin >> i;

  opcion = (Opciones) i;

  switch (opcion) {
  case Primera: hacerPrimera(); break;
  case Segunda: hacerSegunda(); break;
  case Tercera: hacerTercera(); break;
  default: hacerNada(); break;
  }

  return EXIT_SUCCESS;
}

void hacerPrimera() {
  std::cout << "Primera" << std::endl;
}

void hacerSegunda() {
  std::cout << "Segunda" << std::endl;
}

void hacerTercera() {
  std::cout << "Tercera" << std::endl;
}

void hacerNada() {
  std::cout << "Nada" << std::endl;
}

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int
main() {
  float valornotas [] { 261.63f, 293.66f, 329.6f, 349.23f, 392.00f, 440.00f, 493.88f };
  std::string notas [] { "C4"   , "D4"  , "E4"  , "F4"   , "G4"   , "A4"   , "B4"    };

  for (unsigned short i = 1; i < sizeof(valornotas) / sizeof(float); ++i) {
    std::cout << "Diff entre: " << notas[i] << " " << notas[i-1]
	      << " es " << valornotas[i] - valornotas[i-1] << std::endl;
  }

  return EXIT_SUCCESS;
}

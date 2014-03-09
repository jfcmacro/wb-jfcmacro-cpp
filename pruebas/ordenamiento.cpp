#include <iostream>
#include <fstream>
#include <cstdlib>

#define MAX_PALABRA 247000
#define MAX_LINEA   80

using namespace std;

void error(const char* p, const char* p2 = "") {
  cerr << p << ' ' << p2 << endl;
  std::exit(1);
}

char palabra[MAX_PALABRA][MAX_LINEA];

int
main(int argc, char *argv[]) {

  if (argc != 2) error("numero incorrecto de paramentros");

  std::ifstream origen(argv[1]);
  if (!origen) error("no se puede abrir el archivo de entrada", argv[1]);

  /*
  std::ofstream destino(argv[2]);
  if (!destino) error("no se puede abrir el archivo de salida", argv[2]);
  

  char c;
  while (origen.get(c)) destino.put(c);
  */

  int i = 0;
  while (origen.getline(palabra[i++], MAX_LINEA, '\n') && i < MAX_PALABRA && !origen.eof());

  for (int j = 0; j < i; j++) {
    cout << palabra[j] << endl;
  }
  //if (!origen.eof() || !destino) error("¡Sucedio algo extrano!");
}

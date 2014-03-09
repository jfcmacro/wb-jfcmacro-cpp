#include <iostream>
#include <map>

using namespace std;

int
main() {

  int vector[] = { 1144, 5101, 6009, 8010 };

  map<int,int> lista;

  for (int i = 0; i < (sizeof(vector) / sizeof(int)); i++) {
    lista[vector[i]] = i;
  }

  for (int i = (sizeof(vector) / sizeof(int)) - 1; i >= 0; i--) {

    cout << "Elemento: " << vector[i] << " clave: " << lista[vector[i]] << endl;
  }

  return 0;
}

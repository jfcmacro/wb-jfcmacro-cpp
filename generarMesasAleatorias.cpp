#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <map>

using namespace std;

int
main() {

  ifstream ifest("st024420152.dat");
  ifstream imesas("mesas.dat");

  if (!ifest || !imesas) {
    cerr << "No puedo abrir los archivos" << endl;
    return 1;
  }

  const int MAXBUFFER = 256;
  char buffer[MAXBUFFER];
  vector <string> estudiantes;
  int nEst = 0;
  
  while (ifest.getline(buffer, MAXBUFFER)) {
    string nombre(buffer);
    estudiantes.push_back(nombre);
    nEst++;
  }

  int nMesas = 0;
  int mesa;
  vector <int> mesas;
  
  while (imesas >> mesa) {
    mesas.push_back(mesa);
    nMesas++;
  }

  srand(time(NULL));

  for (vector<string>::iterator it = estudiantes.begin();
       it != estudiantes.end(); ++it) {
    int ma = rand() % mesas.size();
    cout << mesas[ma] << *it << endl;
    mesas.erase(mesas.begin() + ma);
  }

  cout << "Total estudiantes: " << nEst << " "
       << estudiantes.size() << endl;
  
  cout << "Total mesas: " << nMesas << " "
       << mesas.size() << endl;
  
  return 0;
}

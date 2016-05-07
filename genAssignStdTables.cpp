#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <map>

using namespace std;

static void usage(const char* filename) {

  cerr << "Usage: " << filename << " <studentfile> <tablefile>" << endl;
  exit(1);
}

int
main(int argc, const char* argv[]) {

  if (argc != 3) {
    
    usage(argv[0]);
  }
  
  ifstream ifest(argv[1]);
  ifstream imesas(argv[2]);

  if (!ifest || !imesas) {
    cerr << "files cannto be opened: " << argv[1]
	 << " " << argv[2] << endl;
    exit(1);
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
  vector<string> mesas;
  
  while (imesas.getline(buffer, MAXBUFFER)) {
    string mesa(buffer);
    mesas.push_back(mesa);
    nMesas++;
  }

  srand(time(NULL));

  for (vector<string>::iterator it = estudiantes.begin();
       it != estudiantes.end(); ++it) {
    int ma = rand() % mesas.size();
    cout << *it << " en la mesa: "  << mesas[ma] << endl;
    mesas.erase(mesas.begin() + ma);
  }

  cout << endl
       << "Assigned students: " << nEst << " "
       << estudiantes.size() << endl;
  
  cout << endl
       << "Remain tables: " << nMesas << " "
       << mesas.size() << endl << endl;

  for (vector<string>::iterator it = mesas.begin();
       it != mesas.end(); ++it) {
    cout << *it << endl;
  }
  
  return 0;
}

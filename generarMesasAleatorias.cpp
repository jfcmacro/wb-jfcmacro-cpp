#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <time.h>

using namespace std;

static void usage(const char* progname) {
  cerr << "Usage: " << progname << " <fichero> <mesas>" << endl;
  exit(1);
}

void partirLinea(const string& linea, string& codigo,
		 string& nombre, string& email) {
  int sep1 = linea.find('|');
  int sep2 = linea.find('|',sep1+1);
  codigo = linea.substr(0,sep1-1);
  nombre = linea.substr(sep1+1, sep2 - (sep1 + 1) );
  email = linea.substr(sep2 + 1);
}

void partirEmail(const string& url, string &email, string host) {
  int sep1 = url.find('@');
  email = url.substr(0, sep1-1);
  host = url.substr(sep1+1);
}

int
main(int argc, const char* argv[]) {

  if (argc != 3) {
    usage(argv[0]);
  }

  string mesaname(argv[2]);

  mesaname = "r" + mesaname;
  
  ifstream ifest(argv[1]);
  ifstream imesas(argv[2]);
  ofstream omesas(mesaname.c_str());

  if (!ifest || !imesas || !omesas) {
    cerr << "No puedo abrir los archivos" << endl;
    return 1;
  }

  const int MAXBUFFER = 256;
  char buffer[MAXBUFFER];
  vector <string> estudiantes;
  int nEst = 0;
  
  while (ifest.getline(buffer, MAXBUFFER)) {
    string nombre;
    string codigo;
    string email;
    partirLinea(buffer,codigo,nombre,email);
    estudiantes.push_back(nombre);
    nEst++;
  }

  int nMesas = 0;
  string mesa;
  vector <string> mesas;
  
  while (imesas >> mesa) {
    mesas.push_back(mesa);
    nMesas++;
  }

  imesas.close();
  ifest.close();
  
  srand(time(NULL));

  for (vector<string>::iterator it = estudiantes.begin();
       it != estudiantes.end(); ++it) {
    int ma = rand() % mesas.size();
    cout << "estudiante: " << *it << " mesa: " << mesas[ma] << endl;
    mesas.erase(mesas.begin() + ma);
  }

  cout << "Total estudiantes: " << nEst << " "
       << estudiantes.size() << endl;
  
  cout << "Total mesas: " << nMesas << " "
       << mesas.size() << endl;

  for (vector<string>::iterator it = mesas.begin();
       it != mesas.end(); ++it) {
    omesas << *it << endl;
  }

  omesas.close();
  
  return 0;
}

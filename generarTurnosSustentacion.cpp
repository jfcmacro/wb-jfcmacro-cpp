#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <map>

using namespace std;

int
main() {

  ifstream ifest("/home/fcardona/tmp/st0244-2015-2-info.dat");

  if (!ifest) {
    cerr << "File cannot be opended" << endl;
    return 1;
  }

  const int MAXBUFFER = 256;
  char buffer[MAXBUFFER];
  vector <string> estudiantes;
  int nEst = 0;
  
  while (ifest.getline(buffer, MAXBUFFER)) {
    string str(buffer);
    stringstream ss(buffer);
    while (ss.good()) {
      string substr;
      getline(ss, substr, ',');
      getline(ss, substr, ',');
      estudiantes.push_back(substr);
      getline(ss, substr, ',');
    }
  }

  srand(time(NULL));
  vector<string> sust1;
  vector<string> sust2;

  int nElem = estudiantes.size() / 2;
  
  for (int i = 0; i < nElem; i++) {
    int ne = rand() % estudiantes.size();
    sust1.push_back(estudiantes[ne]);
    estudiantes.erase(estudiantes.begin() + ne);
  }

  for (vector<string>::iterator it = estudiantes.begin();
       it != estudiantes.end(); ++it) {
    sust2.push_back(*it);
  }

  // cout << "Estudiantes para la primera sustentacion"
  //      << endl;

  ofstream out1("/home/fcardona/tmp/st0244-2015-2-Sust-01.dat");
  
  for (vector<string>::iterator it = sust1.begin();
       it != sust1.end(); ++it) {
    out1 << *it << endl;
  }

  ofstream out2("/home/fcardona/tmp/st0244-2015-2-Sust-02.dat");
 
  for (vector<string>::iterator it = sust2.begin();
       it != sust2.end(); ++it) {
    out2 << *it << endl;
  }
  
  return 0;
}

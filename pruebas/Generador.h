// generador.C
#include <iostream>

using namespace std;

class Generador {
private:
  char *buffer;
  int length;

public:
  
  Generador(char cInicio);
  Generador();
  friend ostream& operator<<(ostream &sout, Generador& g);
  friend istream& operator>>(istream &sin, Generador& g);
  void incrementar();
  bool verificar(int& pos);
};
  

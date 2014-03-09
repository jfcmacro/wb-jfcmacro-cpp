#include <iostream>
#include <iterator>
#include <list>

using namespace std;

class Nodo {
private:
  int x;
public:
  Nodo(int x) {
    this->x = x;
  }

  int obtenerX() {
    return this->x;
  }
};

bool
estaNodo(list<Nodo> &lista, Nodo &nodo) {

  list<Nodo>::iterator primero = lista.begin();
  list<Nodo>::iterator ultimo  = lista.end();

  while (primero != ultimo) {

    if (primero->obtenerX() == nodo.obtenerX()) {
      return true;
    }
    primero++;
  }
  return false;
}

int
main() {

  list<Nodo> lista;

  for (int i = 0; i < 100; i++) {
    lista.push_back(*(new Nodo(i)));
  }

  list<Nodo>::iterator primero = lista.begin();
  list<Nodo>::iterator ultimo  = lista.end();

  while (primero != ultimo) {
    cout << primero->obtenerX() << endl;
    ++primero;
  }

  cout << estaNodo(lista, *(new Nodo(5))) << endl;
  cout << estaNodo(lista, *(new Nodo(1000))) << endl;
  
  return 0;
}

  

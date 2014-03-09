#ifndef ELEMENTO_H
#define ELEMENTO_H "ELEMENTO_H"

#include <iostream>


class Elemento {
 protected:
  Elemento* sig;
 public:
  virtual bool operator>(Elemento&) = 0;
  virtual bool operator<(Elemento&) = 0;
  virtual bool operator<=(Elemento&) = 0;
  virtual bool operator>=(Elemento&) = 0;
  virtual bool operator==(Elemento&) = 0;
  Elemento(Elemento* sig);
  Elemento();
  virtual ~Elemento() {};
  void establecerSiguiente(Elemento *sig);
  Elemento* obtenerSiguiente();
  virtual std::ostream& operator<<(std::ostream &out) = 0;
  friend std::ostream& operator<<(std::ostream& out, Elemento& e) {
    
    return e.operator<<(out);
  }
};

typedef Elemento* PElemento;
#endif

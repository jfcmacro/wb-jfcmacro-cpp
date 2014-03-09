#ifndef ELEMENTOENTERO_H
#define ELEMENTOENTERO_H "ElementoEntero"
#include "Elemento.h"

#include <iostream>

class ElementoEntero : public Elemento {

 public:
  ElementoEntero(int valor);
  ElementoEntero();
  virtual bool operator>(Elemento& el);
  virtual bool operator<(Elemento& el);
  virtual bool operator<=(Elemento& el);
  virtual bool operator>=(Elemento& el);
  virtual bool operator==(Elemento& el);
  virtual std::ostream& operator<<(std::ostream& out);
  friend std::ostream& operator<<(std::ostream& out, ElementoEntero& ee) {
    out << ee;
    return out;
  };
 private:
  int valor;
};
#endif

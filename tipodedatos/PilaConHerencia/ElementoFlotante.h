#ifndef ELEMENTOFLOTANTE_H
#define ELEMENTOFLOTANTE_H "ElementoFlotante"
#include "Elemento.h"

#include <iostream>

class ElementoFlotante : public Elemento {
 public:
  ElementoFlotante(float valor);
  ElementoFlotante();
  virtual bool operator>(Elemento& e);
  virtual bool operator<(Elemento& e);
  virtual bool operator<=(Elemento& e);
  virtual bool operator>=(Elemento& e);
  virtual bool operator==(Elemento& e);
  virtual std::ostream& operator<<(std::ostream& out);
  friend std::ostream& operator<<(std::ostream& out, ElementoFlotante& ef) {
    out << ef.valor;
    return out;
  };
 private:
  float valor;
};
#endif

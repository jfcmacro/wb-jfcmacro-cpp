#include "ElementoEntero.h"

ElementoEntero::ElementoEntero(int valor) : valor(valor) { }

ElementoEntero::ElementoEntero() : valor(0) { }

bool 
ElementoEntero::operator>(Elemento& el) {
  ElementoEntero &ee = dynamic_cast<ElementoEntero&>(el);
  if (this->valor > ee.valor)
    return true;
  
  return false;
}

bool
ElementoEntero::operator<(Elemento& el) {
  ElementoEntero &ee = dynamic_cast<ElementoEntero&>(el);

  if (this->valor < ee.valor)
    return true;

  return false;
}

bool
ElementoEntero::operator>=(Elemento& el) {
  ElementoEntero &ee = dynamic_cast<ElementoEntero&>(el);

  if (this->valor >= ee.valor)
    return true;

  return false;
}

bool
ElementoEntero::operator<=(Elemento& el) {
  ElementoEntero&ee = dynamic_cast<ElementoEntero&>(el);

  if (this->valor >= ee.valor)
    return true;

  return false;
} 

bool
ElementoEntero::operator==(Elemento& el) {
  ElementoEntero&ee = dynamic_cast<ElementoEntero&>(el);

  if (this->valor == ee.valor)
    return true;

  return false;
} 

std::ostream& 
ElementoEntero::operator<<(std::ostream& out) {
    out << valor;
    return out;
}

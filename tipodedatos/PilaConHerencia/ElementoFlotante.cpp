#include "ElementoFlotante.h"

ElementoFlotante::ElementoFlotante(float valor) : valor(valor) { }

ElementoFlotante::ElementoFlotante() : valor(0.0) { }

bool 
ElementoFlotante::operator>(Elemento& e) {
  ElementoFlotante &ef = dynamic_cast<ElementoFlotante&>(e);
  if (this->valor > ef.valor)
    return true;
  
  return false;
}

bool
ElementoFlotante::operator<(Elemento& e) {
  ElementoFlotante &ef = dynamic_cast<ElementoFlotante&>(e);

  if (this->valor < ef.valor)
    return true;

  return false;
}

bool
ElementoFlotante::operator>=(Elemento& e) {
  ElementoFlotante &ef = dynamic_cast<ElementoFlotante&>(e);

  if (this->valor >= ef.valor)
    return true;

  return false;
}

bool
ElementoFlotante::operator<=(Elemento& e) {
  ElementoFlotante&ef = dynamic_cast<ElementoFlotante&>(e);

  if (this->valor >= ef.valor)
    return true;

  return false;
} 

bool
ElementoFlotante::operator==(Elemento& e) {
  ElementoFlotante&ef = dynamic_cast<ElementoFlotante&>(e);

  if (this->valor == ef.valor)
    return true;

  return false;
}

std::ostream& 
ElementoFlotante::operator<<(std::ostream& out) {
    out << valor;
    return out;
}
 

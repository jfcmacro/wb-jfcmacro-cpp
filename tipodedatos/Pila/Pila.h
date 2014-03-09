#ifndef PILA_H_CPP
#define PILA_H_CPP pila_h_cpp

const int NOERROR    = 0;
const int ENOERROR   = NOERROR;
const int ENOMEMORY  = -1;
const int EUNDERFLOW = -2;

struct Elemento;

typedef Elemento* PElemento;

struct Pila {
  PElemento cabeza;
  int nElementos;
  Pila();
  ~Pila();
  int push(int valor);
  int pop(int *valor);
  int tamano() const;
};

#endif 

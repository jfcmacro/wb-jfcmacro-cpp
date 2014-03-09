#ifndef PILA_H_CPP
#define PILA_H_CPP pila_h_cpp

#include <string>
#include <iostream>

#ifdef WINDOWS
#include <ostream>
#include <Windows.h>
#endif

using namespace std;

struct Elemento;

typedef Elemento* PElemento;

class NoMemoryException {
private:
  string mensaje;
public:
  NoMemoryException(char* men);
  NoMemoryException();
  friend ostream& operator<<(ostream &out, NoMemoryException &nme);
};

class UnderflowException {
private:
  string mensaje;
public:
  UnderflowException(char* men);
  UnderflowException();
  friend ostream& operator<<(ostream &out, UnderflowException &ue);
};


class Pila {
private:
  PElemento cabeza;
  int nElementos;
public:
  Pila();
  ~Pila();
  void push(void *valor);
  void* pop();
  int tamano() const;
};

#endif 

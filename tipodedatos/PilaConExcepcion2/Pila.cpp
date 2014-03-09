#include <stdio.h>
#ifndef WINDOWS
#include <string>
#include <iostream>
#else
#include <ostream>
#include <iostream>
#include <string>
#include <Windows.h>
#endif
#include "Pila.h"

using namespace std;

struct Elemento {
  void *valor;
  PElemento sig;

  Elemento(void *valor) {
    this->valor = valor;
    this->sig = NULL;
  }

  Elemento(void *valor, PElemento sig) {
    this->valor = valor;
    this->sig = sig;
  }

  ~Elemento() {
    this->valor = NULL;
    this->sig = NULL;
  }
};


Pila::Pila() {
  cabeza = NULL;
  nElementos = 0;
}

void
Pila::push(void* valor) {
  PElemento pE = new Elemento(valor, cabeza);
  if (pE == NULL)
    throw NoMemoryException();

  cabeza = pE;
  nElementos++;
}

void*
Pila::pop() {
  PElemento pE = cabeza;
  void *valor; 
  if (pE == NULL)
    return NULL;

  valor = pE->valor;
  cabeza = cabeza->sig;
  delete pE;
  return valor;
}  

int
Pila::tamano() const {
  return nElementos;
}

Pila::~Pila() {

  PElemento pE = cabeza;

  while (pE) {
    PElemento pAnt = pE;
    pE = pE->sig;
    delete pAnt;
  }
}

NoMemoryException::NoMemoryException(char* men) : mensaje(men) {
}

NoMemoryException::NoMemoryException(): mensaje("No hay suficiente memoria") {
}

ostream&
operator<<(ostream &out, NoMemoryException& nme) {
    out << nme.mensaje << endl;
    return out;
}




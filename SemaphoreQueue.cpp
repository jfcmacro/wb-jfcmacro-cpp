#include <iostream>
#include <queue>
#include <cstring>
#include "include/SimpleSemaphore.h"

using namespace std;

char buffer[1000000];

int
main(void) {

  queue<SimpleSemaphore*> *lista = new queue<SimpleSemaphore*>();

  ::memcpy(buffer, lista, 80);

  delete lista;
  
  void* tmp = buffer;

  lista = (queue<SimpleSemaphore*>*) tmp;

  SimpleSemaphore* ss = new SimpleSemaphore("/nombreUno");

  lista->push(ss);

  SimpleSemaphore* ss2 = lista->front();
  ss2->Wait();
  lista->pop();

  cout << "Paso" << endl;
  
  return 0;
}

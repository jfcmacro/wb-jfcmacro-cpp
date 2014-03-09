#include<iostream>
#include<stdio.h>

using namespace std;

class CDepth {
private:
  int x;
  CDepth(void);
public:
  static CDepth* current;
  static CDepth* obtenerInstancia();
  int  obtenerEstado();
  void run(void);
  void update(void);
};

CDepth::CDepth() {
}

CDepth* CDepth::current = NULL;

CDepth* CDepth::obtenerInstancia() {

  if (CDepth::current == NULL) {
    CDepth::current = new CDepth();
    }
  return CDepth::current;
}

int CDepth::obtenerEstado() {

  return x;
}

void CDepth::run(void) {

  update();
}

void CDepth::update(void) {

  x++;
}

int obtenerEstado() {
  CDepth *p = CDepth::obtenerInstancia();
  p->update();
  return p->obtenerEstado();
}


void mainLoop(void) {
  ::printf("%d\n", obtenerEstado());
  ::printf("%d\n", obtenerEstado());
}

void argMainLoop(void (*f)(void)) {
  (*f)();
  (*f)();
  return;
}


int
main() {

  argMainLoop(mainLoop);
  return 0;
}

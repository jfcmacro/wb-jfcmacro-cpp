#include <iostream>

class AbsClassWithMethods {
public:
  AbsClassWithMethods() { }
  virtual ~AbsClassWithMethods() = 0;
  virtual void m1() {
    std::cout << "ACWM->m1()" << std::endl;
  }
  virtual void m2() {
    std::cout << "ACWM->m2()" << std::endl;
  }
  virtual void m3() {
    std::cout << "ACWM->m3()" << std::endl;
  }
  virtual void m4() = 0;
private:
};

AbsClassWithMethods::~AbsClassWithMethods() { }

void AbsClassWithMethods::m4() {
    std::cout << "ACWM->m4()" << std::endl;
}

class ConcreteClassWithMethods : public AbsClassWithMethods {
public:
  ConcreteClassWithMethods() : AbsClassWithMethods() {
  }
  ~ConcreteClassWithMethods() {
  }
  void m2() {
    std::cout << "CCWM->m2()" << std::endl;
  }
  void m4() {
    AbsClassWithMethods::m4();
    std::cout << "CCWM->m4()" << std::endl;
  }
};

int
main(void) {

  AbsClassWithMethods *pACWM = new ConcreteClassWithMethods();

  pACWM->m1();
  pACWM->m2();
  pACWM->m3();
  pACWM->m4();
  return 0;
}

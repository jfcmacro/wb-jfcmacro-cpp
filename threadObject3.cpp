#include <iostream>
#include <thread>
#include <cstdlib>

class Test {
  std::thread* thr;
public:
  Test()  {
    std::cout << "Constructor" << std::endl;
    thr = new std::thread([this]{ this->run(); });
  }

  void run() {
    for (int i = 0; i < 10000; i++) {
      std::cout << "Running: " << i << std::endl;
    }
  }

  void join() {
    thr->join();
  }
};

int
main(void) {
  Test t1;

  std::cout << "Waiting for test" << std::endl;
  t1.join();

  return EXIT_SUCCESS;
}

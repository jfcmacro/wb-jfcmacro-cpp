#include <thread>
#include <iostream>
#include <cstdlib>


class Test {
  std::thread thr;
public:
  Test() :
    thr(this)
  {
    std::cout << "Constructor" << std::endl;
  }

  void run() {
    for (int i = 0; i < 10000; i++) {
      std::cout << "Running: " << i << std::endl;
    }
  }

  void join() {
    thr.join();
  }
};

int
main(void) {
  Test t1;

  std::cout << "Waiting for test" << std::endl;
  t1.join();

  return EXIT_SUCCESS;
}

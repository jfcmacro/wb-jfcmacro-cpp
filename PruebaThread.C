#include <thread>
#include <iostream>

using namespace std;

void
f(void) {
  cout << "Imprimendo mensaje 1" << endl;
}

void
g(void) {
  cout << "Imprimendo mensaje 2" << endl;
}



int
main(int argc, char *argv[]) {

  std::thread t1(f);
  std::thread t2(g);
  t1.join();
  t2.join();
  return 0;
}

#include <string>
#include <iostream>

using namespace std;

int
main(void) {
  string vacio;

  cout << "tamano: " << vacio.size() << endl;
  cout << "capacidad: " << vacio.capacity() << endl;
  
  string c("Hola Mundo", 4);

  cout << c << endl;

  string i(10, '*');

  cout << i << endl;
  return 0;
}

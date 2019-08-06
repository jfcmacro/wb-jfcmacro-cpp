#include <iostream>
#include <ios>
#include <cstdlib>

using namespace std;

int
main(void) {
  cout << "Entrar letras en vez de numeros" << endl;

  int i;

  cin >> i;

  if (cin.fail()) {
    cout << "Fallo" << endl;
    cout << "ncaracteres: " << cin.gcount() << endl;
  }

  if (cin.bad()) {
    cout << "Malo" << endl;
    cout << "ncaracteres: " << cin.gcount() << endl;
  }

  return EXIT_SUCCESS;
}

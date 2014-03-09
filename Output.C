#include <iostream>

using namespace std;

void 
val(char c) {
  cout << "int ('" << c << "') = " << int(c) << '\n';
}

int
main() {

  int x;
  x = 10;

  cerr << "x = " << x << endl;
  cout << "expr = " << 3 * (4 << 3) << endl;
  clog << "¿Qué diablos es esto?" << endl;
  cerr.write("hola", 5);
  cerr.put('\n');
  cerr.write("hola", 4);
  cerr.put('\n');
  cerr.write("hola",10);
  val('A');
  val('a');
  cout << true << ' ' << false << endl;
  cout << boolalpha;
  cout << true << ' ' << false << endl;
  
  return 0;
}

#include <iostream>
#include <map>

using namespace std;

int
main() {

  map<char,int> var;

  var['a'] = 10;
  var['b'] = 20;

  cout << "var[a] = " << var['a'] << endl;
  cout << "var[b] = " << var['b'] << endl;
  cout << "var[c] = " << var['c'] << endl;

  return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int
main(void) {
  
  cout << "Digite un entero y flotante: ";
  cout.flush();

  
  string input;
  getline(cin, input);
  
  istringstream iss(input);
  
  string first;
  string second;
  iss >> first >> second;

  int iValue;
  float fValue;

  iValue = stoi(first);
  fValue = stof(second);

  iValue += 10;
  fValue += 20.21f;

  cout << "iValue: " << iValue << endl;
  cout << "fValue: " << fValue << endl;

  return EXIT_SUCCESS;
}

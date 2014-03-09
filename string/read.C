#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

namespace valor {
	int valor;
}

using namespace std;

int
main()
{
  string str;
  char *pointerToChar;

  valor::valor = 110;
  
  cout << "Please enter you name\n";
  getline(cin,str);
  cout << "Hello, " << str << "!\n";
  cout << "Longitud: " << str.length() << endl;
  pointerToChar = new char[str.length() + 1];
  strcpy(pointerToChar, str.c_str()); 
  printf("%s\n", pointerToChar);
  exit(0);
}

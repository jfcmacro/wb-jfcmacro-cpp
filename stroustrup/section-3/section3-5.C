#include <string>
#include <iostream>
#include <stdio.h>

string s1 = "Hello";
string s2 = "world";

void 
m1()
{
  string s3 = s1 + ", " + s2 + "!\n";

  std::cout << s3;
}

void 
m2(string& s1, string& s2)
{
  s1 = s1 + '\n'; // append newline
  s2 += '\n';
}

void 
f()
{
  printf("s1: %d s2: %d\n", s1.c_str(), s2.c_str());
}


int
main()
{
  string s1 = "Prueba";
  string s2 = "Resultado";

  m1();
  m2(s1, s2);
  
  cout << s1 << s2;

  f();
  f();
}

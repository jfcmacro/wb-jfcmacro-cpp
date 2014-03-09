#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <exception>
#include <stdexcept>

map<string,int> phone_book;

void 
print_entry(const string& s)
{
  if (int i = phone_book[s]) cout << s << ' ' << i << endl;
}

int
main()
{
  phone_book.insert("Juan Francisco", 5555);
  phone_book.insert("Angela", 6666);
  
  print_entry("Angela");
}



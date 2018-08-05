#include <iostream>
#include <string>
#include <cstdlib>

int
main(void) {
  std::string::size_type pos;

  std::cin >> pos;
  
  std::string str;

  while (std::getline(std::cin, str)) {
    
    if (str.length() > pos)
      for (std::string::size_type cur = pos;
           cur < str.length();
           ++cur) 
        str.replace(cur, 1, "*");
    std::cout << str << std::endl;
  }
  
  return EXIT_SUCCESS;
}

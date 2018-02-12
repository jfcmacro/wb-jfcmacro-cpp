#include <iostream>
#include <string>

int
main(void) {

  std::string word;
  std::string def;

  std::cin >> word;

  std::string foo;

  std::cin.get();
  getline(std::cin, def);

  std::cout << "word: " << word << " def: " << def << std::endl;
  std::cout << "word lenght: " << word.size() << " def lenght: " << def.size() << std::endl;

  return 0;
}

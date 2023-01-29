#include <iostream>
#include <cstdlib>
#include <string>

std::string binario(int valor);
void reverse(std::string& str);

int
main(int argc, char *argv[]) {

  int in;

  std::cin >> in;

  std::cout << in << " into " << binario(in) << std::endl;

  return EXIT_SUCCESS;
}

std::string
binario(int valor) {
  std::string binStr;
  
  do {
    int d = valor % 2;
    binStr.push_back('0' + (char) d);
  } while (valor /= 2);

  reverse(binStr);
  return binStr;
}


void
reverse(std::string& str) {
  for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
    char tmp = str[j];
    str[j] = str[i];
    str[i] = tmp;
  }
}

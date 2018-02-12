#include <string>
#include <cstdlib>
#include <iostream>

int
checkOddEven(const std::string&, const bool);

int
main(int argc, char *argv[]) {

  std::string str;

  while (std::cin >> str) {
    bool evenOdd = false;
    int len;
    std::size_t n = str.size();
    std::size_t halfN = n / 2;

    std::cout << str
              << ".size()="
              << n
              << " "
              << halfN
              << " ";
    
    len = checkOddEven(str, evenOdd);
    std::cout << len
              << " ";

    bool res = static_cast<bool>(len >= halfN);
    
    std::cout << res;
    evenOdd = !evenOdd;
    len = checkOddEven(str, evenOdd);
    std::cout << " ";
    res = static_cast<bool>(len >= halfN);
    std::cout << len
              << " "
              << res
              << std::endl;
  }

  return EXIT_SUCCESS;
}

int
checkOddEven(const std::string& str, const bool evenOdd) {

  int i,j;
  std::size_t n = str.size();
  std::size_t halfN = n / 2;

  if (n % 2 != 0) halfN++;

  i = evenOdd;

  for (j = i + halfN; i < n/2 && j < n; i += 2, j += 2)
    if (str[i] != str[j])
      break;

  return i;
}

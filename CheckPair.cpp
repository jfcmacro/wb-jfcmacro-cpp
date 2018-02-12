#include <string>
#include <cstdlib>
#include <iostream>

int
checkOddEven(const std::string&, const bool);

int
main(int argc, char *argv[]) {

  std::string str;

  while (cin >> str) {
    bool evenOdd = true;
    cout << str << " " << checkOddEven(str, evenOdd) << endl;
    evenOdd = !evenOdd;
    cout << str << " " << checkOddEven(str, evenOdd) << endl;
  }

  return EXIT_SUCCESS;
}

int
checkOddEven(const std::string& str, const bool evenOdd) {

  int i,j;

  i = oddEven;
  
  for (j = str.size()/2; i < n/2 && j < n; ++i, ++j)
    if (str[i] != str[j])
      break;

  return i;
}

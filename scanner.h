#pragma once
#include <iostream>
#include <istream>
#include "token.h"

class Scanner {
 public:
  Scanner(std::istream* input);
  Token* getToken();
 private:
  std::istream* input;
};

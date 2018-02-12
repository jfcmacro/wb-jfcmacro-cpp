#include "scanner.h"

Scanner::Scanner(std::istream* input) : input(input) { }

Token* Scanner::getToken() {

  enum States { Start, Words, Spaces, NewLines };

  States current_state = Start;

  int cc = input.get();
  
}

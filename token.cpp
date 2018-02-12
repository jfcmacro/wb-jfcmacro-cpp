#include "token.h"

Token::Token(TokenType tokenType, std::string& lexema, int line, int column) :
  tokenType(tokenType), lexema(lexema), line(line), column(column) { }


TokenType
Token::getType() const {
  return tokenType;
}

std::string&
Token:getLexeme() const {
  return lexeme;
}

int
Token::getLine() const {
  return line;
}

int
Token::getColumn() const {
  return column;
}

#pragma once
#include <string>

enum TokenType { Word, Space, NewLine };

class Token {
 public:
  Token(TokenType tokenType, std::string& lexema, int line, int column);
  TokenType getType() const;
  std::string& getLexeme() const;
  int getLine() const;
  int getColumn() const;
 private:
  TokenType tokenType;
  std::string lexeme;
  int line;
  int column;
};

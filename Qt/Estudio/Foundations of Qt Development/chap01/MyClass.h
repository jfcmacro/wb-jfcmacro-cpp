#pragma once

#include <string>

using std::string;

class MyClass {
 public:
  MyClass(const string& text);

  const string& text() const;
  void setText(const string& text);

  int getLengthOfText() const;

 private:
  string m_text;
};

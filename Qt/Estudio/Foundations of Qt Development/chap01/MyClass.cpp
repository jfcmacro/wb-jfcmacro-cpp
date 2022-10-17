#include "MyClass.h"

MyClass::MyClass(const string& text) : m_text(text) { }

const string&
MyClass::text() const {
  return m_text;
}

void
MyClass::setText(const string& text) {
  m_text = text;
}

int
MyClass::getLengthOfText() const {
  return  m_text.size();
}

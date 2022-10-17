#include "MyClassQt.h"

MyClassQt::MyClassQt(const string& text,
		     QObject *parent) : QObject( parent),
					m_text(text) { }

const string&
MyClassQt::text() const {
  return m_text;
}

void
MyClassQt::setText(const string& text) {
  m_text = text;
}

int
MyClassQt::getLengthOfText() const {
  return  m_text.size();
}

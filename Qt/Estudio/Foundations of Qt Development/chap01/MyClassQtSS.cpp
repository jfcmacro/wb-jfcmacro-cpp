#include "MyClassQtSS.h"

MyClassQtSS::MyClassQtSS(const QString& text,
			 QObject *parent)
  : QObject( parent) {
  m_text = text;
}

const QString&
MyClassQtSS::text() const {
  return m_text;
}

void
MyClassQtSS::setText(const QString& text) {
  if (m_text == text)
    return;

  m_text = text;
  emit textChanged(m_text);
}

int
MyClassQtSS::getLengthOfText() const {
  return  m_text.size();
}

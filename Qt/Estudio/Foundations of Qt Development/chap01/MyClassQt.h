#pragma once

#include <QObject>
#include <string>

using std::string;

class MyClassQt : public QObject {
 public:
  MyClassQt(const string& text, QObject *parent = 0);

  const string& text() const;
  void setText(const string& text);

  int getLengthOfText() const;

 private:
  string m_text;
};

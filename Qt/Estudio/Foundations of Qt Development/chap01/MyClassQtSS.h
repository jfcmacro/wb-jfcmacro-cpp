#pragma once

#include <QString>
#include <QObject>
#include <string>

using std::string;

class MyClassQtSS : public QObject {
  Q_OBJECT
 public:
  MyClassQtSS(const QString& text, QObject *parent = 0);

  const QString& text() const;
  int getLengthOfText() const;

public slots:
  void setText(const QString& text);

signals:
  void textChanged(const QString&);
 private:
  QString m_text;
};

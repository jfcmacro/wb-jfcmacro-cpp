#pragma once

#include <QObject>
#include <QDialog>

class Dialog02 : public QObject {
  Q_OBJECT
 public:
  Dialog02(QObject *parent = 0);
  void show();

  public slots:

    void cancel();
    void ok();
 private:
    void setUI();
    QDialog *dlg;
};

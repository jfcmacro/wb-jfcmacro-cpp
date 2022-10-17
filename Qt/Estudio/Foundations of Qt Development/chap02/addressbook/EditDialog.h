#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QtWidgets/QDialog>
#include <QString>
#include "ui_editdialog.h"

class EditDialog : public QDialog {
  Q_OBJECT

 public:
  EditDialog(QWidget * parent = 0);
  const QString name() const;
  void setName(const QString&);

  const QString number() const;
  void setNumber(const QString&);

 private:
    Ui::editDialog ui;
};

#endif // EDITDIALOG_H

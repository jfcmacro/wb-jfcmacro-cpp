#include "dialog02.h"
#include <QWidget>
#include <QDialog>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QPushButton>
#include <cstdlib>

Dialog02::Dialog02(QObject *parent) : QObject(parent),
				      dlg(0) {
  setUI();
}

void
Dialog02::setUI() {
  dlg = new QDialog();

  QGroupBox* groupBox = new QGroupBox("Groupbox");
  QLabel *label =
    new QLabel("Supercalifragilisticexpialidocious");
  QLineEdit *lineEdit = new QLineEdit;
  QDialogButtonBox *buttons =
    new QDialogButtonBox(QDialogButtonBox::Ok |
			 QDialogButtonBox::Cancel);

  QHBoxLayout *hLayout = new QHBoxLayout(groupBox);
  hLayout->addWidget(label);
  hLayout->addWidget(lineEdit);

  QVBoxLayout *vLayout = new QVBoxLayout(dlg);
  vLayout->addWidget(groupBox);
  vLayout->addStretch();
  vLayout->addWidget(buttons);

  QSizePolicy policy = label->sizePolicy();
  policy.setHorizontalStretch(3);
  label->setSizePolicy(policy);
  policy = lineEdit->sizePolicy();
  policy.setHorizontalStretch(1);
  lineEdit->setSizePolicy(policy);

  QPushButton *cancelButton = buttons->button(QDialogButtonBox::Cancel);
  QPushButton *okButton = buttons->button(QDialogButtonBox::Ok);

  QObject::connect(cancelButton, SIGNAL(clicked()),
		   this, SLOT(cancel()));
  QObject::connect(okButton, SIGNAL(clicked()),
		   this, SLOT(ok()));

}

void
Dialog02::cancel() {
  _Exit(EXIT_FAILURE);
}

void
Dialog02::ok() {
  _Exit(EXIT_SUCCESS);
}

void
Dialog02::show() {
  dlg->show();
}

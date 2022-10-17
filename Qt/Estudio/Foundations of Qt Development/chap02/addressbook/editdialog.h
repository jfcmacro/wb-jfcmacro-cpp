/********************************************************************************
 ** Form generated from reading UI file 'editdialog.ui'
 **
 ** Created by: Qt User Interface Compiler version 5.15.3
 **
 ** WARNING! All changes made in this file will be lost when recompiling UI file!
 ********************************************************************************/

#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
  QWidget *layoutWidget;
  QVBoxLayout *verticalLayout;
  QGridLayout *gridLayout;
  QLabel *label;
  QLineEdit *lineEdit;
  QLabel *label_2;
  QLineEdit *lineEdit_2;
  QSpacerItem *verticalSpacer;
  QDialogButtonBox *buttonBox;

  void setupUi(QDialog *EditDialog)
  {
    if (EditDialog->objectName().isEmpty())
      EditDialog->setObjectName(QString::fromUtf8("EditDialog"));
    EditDialog->resize(466, 188);
    layoutWidget = new QWidget(EditDialog);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(80, 30, 361, 131));
    verticalLayout = new QVBoxLayout(layoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(layoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    lineEdit = new QLineEdit(layoutWidget);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

    label_2 = new QLabel(layoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    lineEdit_2 = new QLineEdit(layoutWidget);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

    gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

    verticalLayout->addLayout(gridLayout);

    verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer);

    buttonBox = new QDialogButtonBox(layoutWidget);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    verticalLayout->addWidget(buttonBox);

    retranslateUi(EditDialog);
    QObject::connect(buttonBox, SIGNAL(accepted()), EditDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), EditDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(EditDialog);
  } // setupUi

  void retranslateUi(QDialog *EditDialog)
  {
    EditDialog->setWindowTitle(QCoreApplication::translate("EditDialog", "Dialog", nullptr));
    label->setText(QCoreApplication::translate("EditDialog", "Name:", nullptr));
    label_2->setText(QCoreApplication::translate("EditDialog", "Number:", nullptr));
  } // retranslateUi

};

namespace Ui {
  class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EDITDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'listdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTDIALOG_H
#define UI_LISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_listDialog
{
public:
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer;
    QPushButton *clearButton;
    QListView *list;

    void setupUi(QDialog *listDialog)
    {
        if (listDialog->objectName().isEmpty())
            listDialog->setObjectName(QString::fromUtf8("listDialog"));
        listDialog->resize(368, 294);
        formLayout = new QFormLayout(listDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        addButton = new QPushButton(listDialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_3->addWidget(addButton);

        editButton = new QPushButton(listDialog);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        verticalLayout_3->addWidget(editButton);

        deleteButton = new QPushButton(listDialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout_3->addWidget(deleteButton);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        clearButton = new QPushButton(listDialog);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        verticalLayout_3->addWidget(clearButton);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        list = new QListView(listDialog);
        list->setObjectName(QString::fromUtf8("list"));

        gridLayout->addWidget(list, 0, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout);

        QWidget::setTabOrder(list, addButton);
        QWidget::setTabOrder(addButton, editButton);
        QWidget::setTabOrder(editButton, deleteButton);
        QWidget::setTabOrder(deleteButton, clearButton);

        retranslateUi(listDialog);
        QObject::connect(clearButton, SIGNAL(clicked()), list, SLOT(clearSelection()));

        QMetaObject::connectSlotsByName(listDialog);
    } // setupUi

    void retranslateUi(QDialog *listDialog)
    {
        listDialog->setWindowTitle(QCoreApplication::translate("listDialog", "Phone Book", nullptr));
        addButton->setText(QCoreApplication::translate("listDialog", "Add new", nullptr));
        editButton->setText(QCoreApplication::translate("listDialog", "Edit", nullptr));
        deleteButton->setText(QCoreApplication::translate("listDialog", "Delete", nullptr));
        clearButton->setText(QCoreApplication::translate("listDialog", "Clear all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listDialog: public Ui_listDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTDIALOG_H

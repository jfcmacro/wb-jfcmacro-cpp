#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include "MyClassQtSS.h"

int
main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  qDebug() << "Application created";
  
  QWidget widget;
  QLineEdit *lineEdit = new QLineEdit;
  QLabel *label = new QLabel;

  qDebug() << "Ready to create layout";

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(lineEdit);
  layout->addWidget(label);
  widget.setLayout(layout);

  MyClassQtSS* bridge = new MyClassQtSS("", &app);

  QObject::connect(lineEdit, SIGNAL(textChanged(const QString&)),
		   bridge, SLOT(setText(const QString&)));
  QObject::connect(bridge, SIGNAL(textChanged(const QString&)),
		   label, SLOT(setText(const QString&)));

  qDebug() << "Here";
  
  widget.show();

  qDebug() << "And here";
  
  return app.exec();
}

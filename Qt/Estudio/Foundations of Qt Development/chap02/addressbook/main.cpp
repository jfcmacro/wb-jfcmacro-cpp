#include <QtGui>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "ListDialog.h"

int
main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  ListDialog dlg;

  dlg.show();

  return app.exec();
}

#include <QtGui>
#include <QApplication>
#include "dialog02.h"

void
cancelFun() {
  _Exit(EXIT_FAILURE);
}

void
acceptFun() {
  _Exit(EXIT_SUCCESS);
}

int
main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Dialog02 dlg;

  dlg.show();

  return app.exec();
}

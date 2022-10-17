#include <QtDebug>
#include <cstdlib>
#include "MyClassQt.h"

int
main(int argc, char *argv[]) {
  QObject parent;
  MyClassQt *a, *b, *c;

  a = new MyClassQt("foo", &parent);
  b = new MyClassQt("ba-a-ar", &parent);
  c = new MyClassQt("baz", &parent);


  qDebug() << QString::fromStdString(a->text())
	   << " (" << a->getLengthOfText()
	   << ")";
  qDebug() << QString::fromStdString(b->text())
	   << " (" << b->getLengthOfText()
	   << ")";
  qDebug() << QString::fromStdString(c->text())
	   << " (" << c->getLengthOfText()
	   << ")";

  int result = a->getLengthOfText() - c->getLengthOfText();

  qDebug() << QString::fromStdString("Result: ") << result;

  return EXIT_SUCCESS;
}

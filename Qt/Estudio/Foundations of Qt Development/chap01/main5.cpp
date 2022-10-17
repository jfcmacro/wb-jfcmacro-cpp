#include <QtDebug>
#include <cstdlib>
#include "MyClassQtSS.h"

int
main(int argc, char *argv[]) {
  QObject parent;
  MyClassQtSS *a, *b, *c;

  a = new MyClassQtSS("foo", &parent);
  b = new MyClassQtSS("bar", &parent);
  c = new MyClassQtSS("baz", &parent);

  QObject::connect(a, SIGNAL(textChanged(const QString&)),
		   b, SLOT(setText(const QString&)));
  QObject::connect(b, SIGNAL(textChanged(const QString&)),
		   c, SLOT(setText(const QString&)));
  QObject::connect(c, SIGNAL(textChanged(const QString&)),
		   b, SLOT(setText(const QString&)));

  b->setText("test");

  qDebug() << a->text()
	   << " (" << a->getLengthOfText()
	   << ")";
  qDebug() << b->text()
	   << " (" << b->getLengthOfText()
	   << ")";
  qDebug() << c->text()
	   << " (" << c->getLengthOfText()
	   << ")";

  a->setText("Qt");

  qDebug() << a->text()
	   << " (" << a->getLengthOfText()
	   << ")";
  qDebug() << b->text()
	   << " (" << b->getLengthOfText()
	   << ")";
  qDebug() << c->text()
	   << " (" << c->getLengthOfText()
	   << ")";

  int result = a->getLengthOfText() - c->getLengthOfText();

  qDebug() << QString::fromStdString("Result: ") << result;

  return EXIT_SUCCESS;
}

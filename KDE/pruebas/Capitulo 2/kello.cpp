#include <qstring.h>
#include <kapp.h>
#include <klineedit.h>

int
main(int argc, char *argv[]) {

  KApplication khello(argc, argv, "khello");
  KLineEdit *helloedito = new KlineEdit(0);
  QString hellostring("¡Hola!");
  helloeditor->setText(hellostring);
  helloeditor->show();

  khello.setMainWidget(helloeditor);
  return khello.exec();
}

#include <qstring.h>
#include <kapp.h>
#include <klineedit.h>

int
main(int argc, char *argv[]) {

  KApplication khello(argc, argv, "khello");
  KLineEdit *helloeditor; //  new KlineEdit();
  QString hellostring("¡Hola!");
  helloeditor = new KLineEdit();
  helloeditor->setText(hellostring);
  helloeditor->show();

  khello.setMainWidget(helloeditor);
  return khello.exec();
}

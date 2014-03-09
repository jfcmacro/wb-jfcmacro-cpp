#include <kapp.h>

#include "ksimpleapp.h"

int
main(int argc, char *argv[]) {

  KApplication kapplication (argc, argv, "ksimpleapp");

  if (kapplication.isRestored())
    RESTORE(KSimpleApp);
  else {
    KSimpleApp *ksimpleapp = new KSimpleApp;
    ksimpleapp->show();
  }
  return kapplication.exec();
}

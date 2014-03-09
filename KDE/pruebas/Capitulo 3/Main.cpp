#include <qapplication.h>
#include "MyWindow.hpp"

int
main(int argc, char *argv[]) {

  QApplication q(argc, argv);

  MyWindow window;

  window.setGeometry(100,100,400,300);
  
  q.setMainWidget(&window);

  window.show();

  return q.enter_loop();
}

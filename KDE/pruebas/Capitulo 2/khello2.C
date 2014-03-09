/************* khello.cc *******************/
#include <kapp.h>
#include <kmainwindow.h>

int main( int argc, char **argv )
{
  KApplication a( argc, argv, "khello" );
  KMainWindow *w = new KMainWindow();
  w->setGeometry(100,100,200,100);

  a.setMainWidget( w );
  w->show();
  return a.exec();
}
/************* end of file *****************/

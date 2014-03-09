#include <kapplication.h>
#include <qpushbutton.h>
#include <qwidget.h>

class MyWindow : public QWidget {

public:
  
  MyWindow();

private:
  QPushButton *button;
};

MyWindow::MyWindow() : QWidget() {

  button = new QPushButton("Botón", this);

  button->setGeometry(100,50, 100, 30);
  
  button->show();
}

int
main(int argc, char *argv[]) {

  KApplication app(argc, argv, "Botones");

  MyWindow window;

  window.setGeometry(200, 200, 300, 130);
  
  window.setCaption("Ejemplo de QPushButton");

  app.setMainWidget(&window);

  window.show();

  return app.exec();
}

#include <kapplication.h>
#include <qwidget.h>
#include <qpainter.h>

class MyWindow : public QWidget {

public:
  
  MyWindow() : QWidget() { }

protected:

  void mousePressEvent(QMouseEvent *event);
};

void MyWindow::mousePressEvent(QMouseEvent *event) {
  
  static int x1 = -1, x2 = -1, y1 = -1, y2 = -1;

  if (x1 != -1) {
    x2 = event->x();
    y2 = event->y();
      
    QPainter paint(this);

    paint.drawLine(x1, y1, x2, y2);
    x1 = x2 = y1 = y2 = -1;
  }
  else {
    x1 = event->x();
    y1 = event->y();
  }
}

int
main(int argc, char *argv[]) {

  KApplication app(argc, argv, "Botones");

  MyWindow window;

  window.setGeometry(200, 200, 400, 300);
  
  window.setCaption("Ejemplo de QWidget");

  window.show();

  return app.exec();
}

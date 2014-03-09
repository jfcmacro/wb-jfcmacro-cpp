#include <kapp.h>
#include <qwidget.h>
#include <qpainter.h>
#include <qimage.h>

class MyWindow : public QWidget {

public:
  MyWindow() : QWidget() { }
protected:
  void paintEvent(QPaintEvent *);
};

void MyWindow::paintEvent(QPaintEvent *) {

  QImage image;

  if (image.load("FedoV-monalisa-1.jpg", 0)) {

    QPainter paint(this);
    paint.drawImage(0, 0, image, 0, 0, image.width(), image.height());
  }
}

int
main(int argc, char *argv[]) {

  KApplication app(argc, argv, "ImageIO");

  MyWindow window;
  app.setMainWidget(&window);
  window.setCaption("Ejemplo de imageIO");
  window.setGeometry(100,100,300,300);
  window.show();
  return app.exec();
}

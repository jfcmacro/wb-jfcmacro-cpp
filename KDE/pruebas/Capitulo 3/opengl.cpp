#include <kapplication.h>
#include <qgl.h>

// El QGLWidgetes un QWidget con soporte para OpenGL
class MyWindow : public QGLWidget {

public: 
  MyWindow() : QGLWidget() { }
protected:
  void initializeGL();
  void resizeGL(int, int);
  void paintGL();
};

void 
MyWindow::initializeGL() {

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
}

void
MyWindow::paintGL() 
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  glColor3f(0.0, 0.1, 0.4);

  glBegin(GL_POLYGON);
  glVertex3f(3.0, 5.5, 0.0);
  glVertex3f(5.0, 8.0, 0.0);
  glVertex3f(7.0, 5.5, 0.0);
  glEnd();

  glBegin(GL_LINE_LOOP);
  glVertex3f(3.0, 4.5, 0.0);
  glVertex3f(5.0, 2.0, 0.0);
  glVertex3f(7.0, 4.5, 0.0);
  glEnd();

  glFlush();
}

void
MyWindow::resizeGL(int w, int h) {

  glViewport(0, 0, (GLint) w, (GLint) h);
}

int
main(int argc, char *argv[]) {
  
  KApplication app(argc, argv, "OGL");
  MyWindow window;
  window.setGeometry(100,100,300,200);
  window.setCaption("Extensión de OpenGL");
  app.setMainWidget(&window);
  window.show();
  return app.exec();
}

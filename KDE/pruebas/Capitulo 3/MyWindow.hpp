#include <qwidget.h>
#include <qpushbutton.h>


class MyWindow : public QWidget
{
  Q_OBJECT
public:
  MyWindow();
private slots:
  void slotButton1();
  void slotButton2();
  void slotButtons();
private:
  QPushButton *button1;
  QPushButton *button2;
};


/**
 *
 */
#include <kmainwindo.h>

class QLabel;

class KSimpleApp : public KMainWindow
{
Q_OBJECT

public:
  KSimpleApp(const char *name = 0);
  
public slots:
  void slotRepositionText();

 private:

  QLabel *text;
  int aligment[3], indexaligment;
};

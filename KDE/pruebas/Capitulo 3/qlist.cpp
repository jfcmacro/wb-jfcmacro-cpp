#include <qlist.h>
#include <iostream.h>

class MyClass {

public:
  MyClass() { t = 3; }
  int get() { return t++; }
private:
  int t;
};

int
main() {

  QList<MyClass> list;
  MyClass *temp;

  list.setAutoDelete(TRUE);

  for (int i = 0; i < 3; i++) {
    temp = new MyClass;

    list.append(temp);
  }

  for (temp = list.first(); temp != 0; temp = list.next())
    cout << temp->get() << endl;

}

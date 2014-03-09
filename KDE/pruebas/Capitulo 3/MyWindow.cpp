#include "MyWindow.moc"
#include <iostream>

MyWindow::MyWindow() : QWidget() {

  // Crea el button1 y conecta button1->clicked() a this->slotButton1()

  button1 = new QPushButton("Botón 1", this);
  button1->setGeometry(10,10,100,40);
  button1->show();
  connect(button1, SIGNAL(clicked()), this, SLOT(slotButton1()));

  // Crea button2 y conecta button2->clicked() a this->slotButton2()

  button2 = new QPushButton("Botón 2", this);
  button2->setGeometry(110, 10, 100, 40);
  button2->show();
  connect(button2, SIGNAL(clicked()), this, SLOT(slotButton2()));

  // Cuando preciona un boton, se invoca this->slotButtons()
  connect(button1, SIGNAL(clicked()), this, SLOT(slotButtons()));
  connect(button2, SIGNAL(clicked()), this, SLOT(slotButtons()));
}

void MyWindow::slotButton1() {
  cout << "Botón 1 fue presionado" << endl;
}

void MyWindow::slotButton2() {
  cout << "Botón 2 fue presionado" << endl;
}

void MyWindow::slotButtons() {
  cout << "Se presionó un botón" << endl;
}
  

all: ex01 ex02 ex03 ex04 ex05 ex06

CXXFLAGS=-I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtWidgets -DQT_DEBUG_OUTPUT
LDFLAGS=-lQt5Core -lQt5Gui -lQt5Widgets
MOC=/usr/lib64/qt5/bin/moc

ex01: main.o MyClass.o
	${CXX} -o $@ $^ 

ex02: main2.o MyClassQt.o
	${CXX} -o $@ $^ ${LDFLAGS}

ex03: main3.o MyClassQt.o
	${CXX} -o $@ $^ ${LDFLAGS}

ex04: main4.o
	${CXX} -o $@ $^ ${LDFLAGS}

ex05: main5.o MyClassQtSS.o moc_MyClassQtSS.o
	${CXX} -o $@ $^ ${LDFLAGS}

ex06: main6.o MyClassQtSS.o moc_MyClassQtSS.o
	${CXX} -o $@ $^ ${LDFLAGS}

moc_MyClassQtSS.cpp: MyClassQtSS.h
	${MOC} -o $@ $<

clean:
	rm -f *.o
	rm -f *.*~
	rm -f ex0?
	rm -f moc_MyClassQtSS.cpp

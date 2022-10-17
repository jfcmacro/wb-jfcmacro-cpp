all: ex02

CXXFLAGS=-I/usr/include/qt5 -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtGui -I/usr/include/qt5/QtWidgets -DQT_DEBUG_OUTPUT
LDFLAGS=-lQt5Core -lQt5Gui -lQt5Widgets
MOC=/usr/lib64/qt5/bin/moc
UIC=/usr/lib64/qt5/bin/uic

ui_ex01.h: ex01.ui
	${UIC} $< -o $@

ex02: ex02.o dialog02.o moc_dialog02.o
	${CXX} -o $@ $^ ${LDFLAGS}

moc_dialog02.cpp: dialog02.h
	${MOC} -o $@ $<

clean:
	rm -f *.o
	rm -f *.*~
	rm -f ex0?
	rm -f ui_ex01.h
	rm -f moc_dialog02.cpp moc_dialog02.o

QTDIR = /usr/lib/qt-3.0.5
KDEDIR = /usr/include/kde
QTINC = -I$(QTDIR)/include
KDEINC = -I$(KDEDIR)/
QTLIB = -L$(QTDIR)/lib
KDELIB = 
QTBIN = $(QTDIR)/bin

all: widget button main qlist qptrlist imageio opengl

widget: widget.o
	g++ -o $@ $(QTLIB) $(KDELIB) -lkdeui -lkdecore -lqt -ldl $<

widget.o: widget.cpp
	g++ -c $(QTINC) $(KDEINC) $<

button: button.o	
	g++ -o 	$@ $(QTLIB) $(KDELIB) -lkdeui -lkdecore -lqt -ldl $<

button.o: button.cpp
	g++ -c $(QTINC) $(KDEINC) $<

main:	Main.o MyWindow.o
	g++ -o $@ $(QTLIB) -lqt -ldl Main.o MyWindow.o

Main.o: Main.cpp MyWindow.hpp
	g++ -c $(QTINC) $<

MyWindow.o: MyWindow.cpp MyWindow.moc
	g++ -c $(QTINC) MyWindow.cpp

MyWindow.moc: MyWindow.hpp
	$(QTBIN)/moc $< > $@

qlist: 	qlist.o
	g++ -o $@ $(QTLIB) -lqt -ldl $<

qlist.o: qlist.cpp
	g++ -c $(QTINC) $<

qptrlist: qptrlist.o
	g++ -o $@ $(QTLIB) -lqt -ldl $<

qptrlist.o: qptrlist.cpp
	g++ -c $(QTINC) $<

imageio: imageio.o
	g++ -o $@ $(QTLIB) $(KDELIB) -lkdeui -lkdecore -lqt -ldl $<

imageio.o: imageio.cpp
	g++ -c $(QTINC) $(KDEINC) $<

opengl: opengl.o
	g++ -o $@ $(QTLIB) $(KDELIB) -lkdeui -lkdecore -lqt -ldl $<

opengl.o: opengl.cpp
	g++ -c $(QTINC) $(KDEINC) $<
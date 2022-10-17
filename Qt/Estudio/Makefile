QTDIR=/usr/include/qt5/QtWidgets
QTLIB=/usr/

CXXFLAGS = -I $(QTDIR) -I $(QTDIR)/.. -I $(QTDIR)/../QtGui
LDFLAGS  = -L $(QTLIB)/lib -lqt 

all: t8 hello

t8: main.o cannon.o lcdrange.o
	g++ -o $@ main.o cannon.o lcdrange.o $(LDFLAGS)

Hello: Hello.o
	g++ -o $@ $< $(LDFLAGS)

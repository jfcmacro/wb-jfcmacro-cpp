CXXFLAGS = -I $(QTDIR)/include 
LDFLAGS  = -L $(QTDIR)/lib -lqt 

all: t8 hello

t8: main.o cannon.o lcdrange.o
	g++ -o $@ main.o cannon.o lcdrange.o $(LDFLAGS)


hello: hello.cpp
	g++ -o $@ $< $(LDFLAGS)

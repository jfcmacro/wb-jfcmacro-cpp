CXXFLAGS= -g -Wall

all:	Main1 Main2

Main1: Main1.o Elemento.o ElementoEntero.o Pila.o
	g++ -o $@ Main1.o Elemento.o ElementoEntero.o Pila.o

Main2: Main2.o Elemento.o ElementoFlotante.o Pila.o
	g++ -o $@ Main2.o Elemento.o ElementoFlotante.o Pila.o

Main1.o: Main1.cpp Pila.h ElementoEntero.h 

Elemento.o: Elemento.cpp Elemento.h

Pila.o: Pila.cpp Pila.h Elemento.h

ElementoEntero.o: ElementoEntero.cpp ElementoEntero.h Elemento.h

ElementoFlotante.o: ElementoFlotante.cpp ElementoFlotante.h Elemento.h
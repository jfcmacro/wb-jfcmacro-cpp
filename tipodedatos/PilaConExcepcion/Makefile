CPPFLAGS = 

all: Main

Main: Main.o Pila.o 
	g++ -o $@ Main.o Pila.o

Pila.o: Pila.cpp Pila.h

Main.o: Main.cpp Pila.h

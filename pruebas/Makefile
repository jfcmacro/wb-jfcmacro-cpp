CXXFLAGS= -g 

all: Paso1 Paso2 Paso3

Paso1: Main.o Generador.o 
	g++ -o $@ Main.o Generador.o

Paso2: Main2.o Generador.o
	g++ -o $@ Main2.o Generador.o

Paso3: Main3.o Generador.o
	g++ -o $@ Main3.o Generador.o

Generador.o: Generador.C Generador.h
	g++ -c ${CXXFLAGS} Generador.C

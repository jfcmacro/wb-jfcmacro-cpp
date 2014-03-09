CPPFLAGS = /DWINDOWS /GX

all: Main

Main: Main.obj Pila.obj Pila.h
 	cl  /Fe$@ Main.obj Pila.obj

Pila.obj: Pila.cpp Pila.h

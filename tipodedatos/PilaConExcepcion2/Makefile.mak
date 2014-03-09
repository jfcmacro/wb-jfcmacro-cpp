CPPFLAGS = /DWINDOWS /GX /TP

all: Main

Main: Main.obj Pila.obj
	cl  /Fe$@ Main.obj Pila.obj

Pila.obj: Pila.cpp Pila.h

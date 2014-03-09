CPPFLAGS= /DWINDOWS /GX /GR

all:	Main1 Main2

Main1: Main1.obj Elemento.obj ElementoEntero.obj Pila.obj
	cl  /Fe$@ Main1.obj Elemento.obj ElementoEntero.obj Pila.obj

Main2: Main2.obj Elemento.obj ElementoFlotante.obj Pila.obj
	cl  /Fe$@ Main2.obj Elemento.obj ElementoFlotante.obj Pila.obj

Main1.obj: Main1.cpp Pila.h ElementoEntero.h 

Elemento.obj: Elemento.cpp Elemento.h

Pila.obj: Pila.cpp Pila.h Elemento.h

ElementoEntero.obj: ElementoEntero.cpp ElementoEntero.h Elemento.h

ElementoFlotante.obj: ElementoFlotante.cpp ElementoFlotante.h Elemento.h

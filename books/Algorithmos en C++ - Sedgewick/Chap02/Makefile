all: ejercicio1 ejercicio2 ejercicio3

euclides.o: euclides.cpp euclides.h

ejercicio1: main-ejercicio1.o euclides.o
	${CXX} -o $@ $^

main-ejercicio1.o: main-ejercicio1.cpp euclides.h

ejercicio2: main-ejercicio2.o euclides.o
	${CXX} -o $@ $^

main-ejercicio2.o: main-ejercicio2.cpp euclides.h

fraccion.o: fraccion.cpp fraccion.h euclides.h

ejercicio3: main-ejercicio3.o euclides.o fraccion.o
	${CXX} -o $@ $^

main-ejercicio3.o: main-ejercicio3.cpp fraccion.h

clean:
	rm -f *.o
	rm -f *.*~ rm *~
	rm -f ejercicio1 ejercicio2 ejercicio3


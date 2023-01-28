all: ejercicio1 euclides2 ejercicio3

ejercicio1: main-ejercicio1.o euclides.o
	${CXX} -o $@ $^

main-ejercicio1.o: main-ejercicio1.cpp euclides.h

euclides2: main-euclides2.o euclides2.o
	${CXX} -o $@ $^

euclides2.o: euclides2.cpp

euclides.o: euclides.cpp euclides.h

main-euclides2.o: main-euclides2.cpp euclides.h

ejercicio3: ejercicio3.o euclides2.o
	${CXX} -o $@ $^

ejercicio3.o: ejercicio3.cpp euclides.h

clean:
	rm -f *.o
	rm -f *.*~ rm *~
	rm -f ejercicio1

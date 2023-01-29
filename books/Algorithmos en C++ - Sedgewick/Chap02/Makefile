EXEC=ejercicio1 ejercicio2 ejercicio3 ejercicio4 ejercicio5
all: ${EXEC}

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

ejercicio4: main-ejercicio4.o
	${CXX} -o $@ $^

main-ejercicio4.o: main-ejercicio4.cpp

ejercicio5: main-ejercicio5.o
	${CXX} -o $@ $^

main-ejercicio5.o: main-ejercicio5.cpp

clean:
	rm -f *.o
	rm -f *.*~ rm *~
	rm -f ${EXEC}

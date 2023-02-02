EXEC=eratostenes josefo

all: ${EXEC}

eratostenes: eratostenes.o
	${CXX} -o $@ $^

eratostenes.o: eratostenes.cpp

josefo: josefo.o node.o
	${CXX} -o $@ $^

josefo.o: josefo.cpp node.h

node.o: node.cpp node.h

clean:
	rm -f *.o *.*~ *~
	rm eratostenes

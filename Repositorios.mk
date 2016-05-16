all: traerRepositorios

traerRepositorios: traerRepositorios.o estudiante.o
	$(CXX) -o $@ $^

traerRepositorios.o: traerRepositorios.cpp estudiante.h

estudiante.o: estudiante.cpp estudiante.h

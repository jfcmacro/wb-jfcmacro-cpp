all: traerRepositorios procesarSalidaAWKMosaico

CXXFLAGS=-Wall

traerRepositorios: traerRepositorios.o estudiante.o
	$(CXX) -o $@ $^

traerRepositorios.o: traerRepositorios.cpp estudiante.h

estudiante.o: estudiante.cpp estudiante.h

procesarSalidaAWKMosaico: procesarSalidaAWKMosaico.o
	$(CXX) -o $@ $<

procesarSalidaAWKMosaico.o: procesarSalidaAWKMosaico.cpp

clean:
	rm -f traerRepositorios.o procesarSalidaAWKMosaico.o estudiante.o
	rm -f traerRepositorio procesarSalidaAWKMosaico

all: getRepo procesarSalidaAWKMosaico

CXXFLAGS=-Wall

getRepo: getRepo.o estudiante.o gradeprocess.o
	$(CXX) -o $@ $^

getRepo.o: getRepo.cpp estudiante.h gradeprocess.h

gradeprocess.o: gradeprocess.cpp gradeprocess.h

estudiante.o: estudiante.cpp estudiante.h

procesarSalidaAWKMosaico: procesarSalidaAWKMosaico.o
	$(CXX) -o $@ $<

procesarSalidaAWKMosaico.o: procesarSalidaAWKMosaico.cpp

clean:
	rm -f getRepo.o procesarSalidaAWKMosaico.o estudiante.o
	rm -f traerRepositorio procesarSalidaAWKMosaico

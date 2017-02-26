CXXFLAGS=-std=c++11 -g
LDFLAGS2=-lpthread -ldl -lsqlite3 -lmongoclient -lboost_system

all: generarMesasAleatorias generarTurnosSustentacion euLoadStudentsCourseDB launchCmdsPipe

generarMesasAleatorias: generarMesasAleatorias.o
	$(CXX) -o $@ $^

generarTurnosSustentacion: generarTurnosSustentacion.o
	$(CXX) -o $@ $^

euLoadStudentsCourseDB: euLoadStudentsCourseDB.o euData.o
	$(CXX) -o $@ $^ $(LDFLAGS2)

euLoadStudentsCourseDB.o: euLoadStudentsCourseDB.cpp euData.h
	@echo $(CXXFLAGS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

launchCmdsPipe: launchCmdsPipe.o process.o
	$(CXX) -o $@ $^

launchCmdsPipe.o: launchCmdsPipe.cpp process.h

process.o: process.cpp process.h

euData.o: euData.cpp euData.h

clean:
	rm -f generarMesasAleatorias.o generarTurnosSustentacion.o eafitCVS2StdInfo.o euLoadStudentsCourseDB.o
	rm -f generarMesasAleatorias generarTurnosSustentacion eafitCVS2StdInfo euLoadStudentsCourseDB
	rm -f launchCmdsPipe.o process.o
	rm -f launchCmdsPipe

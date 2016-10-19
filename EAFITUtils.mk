CXXFLAGS=
LDFLAGS2=-lpthread -ldl -lsqlite3 -lmongoclient -lboost_system

all: eafitCVSInfo2StdInfo generarMesasAleatorias generarTurnosSustentacion euLoadStudentsCourseDB

eafitCVSInfo2StdInfo: eafitCVSInfo2StdInfo.o
	$(CXX) -o $@ $^ 

generarMesasAleatorias: generarMesasAleatorias.o
	$(CXX) -o $@ $^

generarTurnosSustentacion: generarTurnosSustentacion.o
	$(CXX) -o $@ $^

euLoadStudentsCourseDB: euLoadStudentsCourseDB.o euData.o
	$(CXX) -o $@ $^ $(LDFLAGS2)

euLoadStudentsCourseDB.o: euLoadStudentsCourseDB.cpp euData.h
	@echo $(CXXFLAGS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

euData.o: euData.cpp euData.h

clean:
	rm -f generarMesasAleatorias.o generarTurnosSustentacion.o eafitCVS2StdInfo.o euLoadStudentsCourseDB.o
	rm -f generarMesasAleatorias generarTurnosSustentacion eafitCVS2StdInfo euLoadStudentsCourseDB

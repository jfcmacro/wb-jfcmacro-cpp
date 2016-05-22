all: getStdRepos eafitCVSInfo2StdInfo.cpp

CXXFLAGS=-Wall

getStdRepos: getStdRepos.o stdinfo.o gradeprocess.o
	$(CXX) -o $@ $^

getStdRepos.o: getStdRepos.cpp stdinfo.h gradeprocess.h

gradeprocess.o: gradeprocess.cpp gradeprocess.h

stdinfo.o: stdinfo.cpp stdinfo.h

eafitCVSInfo2StdInfo: eafitCVSInfo2StdInfo.o
	$(CXX) -o $@ $<

eafitCVSInfo2StdInfo.o: eafitCVSInfo2StdInfo.cpp

clean:
	rm -f getStdRepos.o eafitCVSInfo2StdInfo.o stdinfo.o
	rm -f traerRepositorio eafitCVSInfo2StdInfo

all: getStdRepos eafitCVSInfo2StdInfo evalStdRepos printYamlFile printEvalUnit

CXXFLAGS=-Wall -std=c++11

getStdRepos: getStdRepos.o stdinfo.o stdreposutils.o
	$(CXX) -o $@ $^ -lyaml-cpp -L/usr/local/lib

getStdRepos.o: getStdRepos.cpp stdinfo.h stdreposutils.h

stdreposutils.o: stdreposutils.cpp stdreposutils.h

stdinfo.o: stdinfo.cpp stdinfo.h stdreposutils.h

eafitCVSInfo2StdInfo: eafitCVSInfo2StdInfo.o
	$(CXX) -o $@ $<

eafitCVSInfo2StdInfo.o: eafitCVSInfo2StdInfo.cpp

evalStdRepos: evalStdRepos.o stdreposutils.o stdinfo.o
	$(CXX) -o $@ $^ -lyaml-cpp -L/usr/local/lib

evalStdRepos.o: evalStdRepos.cpp stdreposutils.h stdinfo.h

printEvalUnit: printEvalUnit.o stdreposutils.o stdinfo.o
	$(CXX) -o $@ $^ -lyaml-cpp -L/usr/local/lib

printEvalUnit.o: printEvalUnit.cpp stdreposutils.h

printYamlFile: printYamlFile.o
	$(CXX) -o $@ $^ -lyaml-cpp -L/usr/local/lib

printYamlFile.o: printYamlFile.cpp
clean:
	rm -f getStdRepos.o eafitCVSInfo2StdInfo.o stdinfo.o stdreposutils.o evalStdRepos.o printYamlFile.o
	rm -f traerRepositorio eafitCVSInfo2StdInfo evalStdRepos evalStdRepos3 printYamlFile
	rm -f printEvalUnit

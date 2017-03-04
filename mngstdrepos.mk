EXECS=getStdRepos eafitCVSInfo2StdInfo evalStdRepos printYamlFile printEvalUnit fromClipBoard2StdInfo testProcess

all: $(EXECS)

CXXFLAGS=-Wall -std=c++11

getStdRepos: getStdRepos.o stdinfo.o stdreposutils.o
	$(CXX) -o $@ $^ -lyaml-cpp -L/usr/local/lib

getStdRepos.o: getStdRepos.cpp stdinfo.h stdreposutils.h

stdreposutils.o: stdreposutils.cpp stdreposutils.h

stdinfo.o: stdinfo.cpp stdinfo.h stdreposutils.h

eafitCVSInfo2StdInfo: eafitCVSInfo2StdInfo.o
	$(CXX) -o $@ $<

eafitCVSInfo2StdInfo.o: eafitCVSInfo2StdInfo.cpp

fromClipBoard2StdInfo: fromClipBoard2StdInfo.o process.o
	$(CXX) -o $@ $^

fromClipBoard2StdInfo.o: fromClipBoard2StdInfo.cpp process.h

evalStdRepos: evalStdRepos.o stdreposutils.o stdinfo.o process.o
	$(CXX) -o $@ $^ -lyaml-cpp -L/usr/local/lib

evalStdRepos.o: evalStdRepos.cpp stdreposutils.h stdinfo.h

printEvalUnit: printEvalUnit.o stdreposutils.o stdinfo.o
	$(CXX) -o $@ $^ -lyaml-cpp -L/usr/local/lib

printEvalUnit.o: printEvalUnit.cpp stdreposutils.h

process.o: process.cpp process.h

printYamlFile: printYamlFile.o
	$(CXX) -o $@ $^ -lyaml-cpp -L/usr/local/lib

testProcess: testProcess.o process.o
	$(CXX) -o $@ $^

testProcess.o: testProcess.cpp

printYamlFile.o: printYamlFile.cpp
clean:
	rm -f getStdRepos.o eafitCVSInfo2StdInfo.o stdinfo.o stdreposutils.o evalStdRepos.o printYamlFile.o
	rm -f fromClipBoard2StdInfo.o
	rm -f traerRepositorio eafitCVSInfo2StdInfo evalStdRepos evalStdRepos3 printYamlFile
	rm -f printEvalUnit fromClipBoard2StdInfo

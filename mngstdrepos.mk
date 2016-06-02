all: getStdRepos eafitCVSInfo2StdInfo evalStdRepos printYamlFile

CXXFLAGS=-Wall

getStdRepos: getStdRepos.o stdinfo.o stdreposutils.o
	$(CXX) -o $@ $^ -lyaml-cpp03

getStdRepos.o: getStdRepos.cpp stdinfo.h stdreposutils.h

stdreposutils.o: stdreposutils.cpp stdreposutils.h

stdinfo.o: stdinfo.cpp stdinfo.h stdreposutils.h

eafitCVSInfo2StdInfo: eafitCVSInfo2StdInfo.o
	$(CXX) -o $@ $<

eafitCVSInfo2StdInfo.o: eafitCVSInfo2StdInfo.cpp

evalStdRepos: evalStdRepos.o stdreposutils.o stdinfo.o
	$(CXX) -o $@ $^ -lyaml-cpp03

evalStdRepos.o: evalStdRepos.cpp stdreposutils.h stdinfo.h

# evalStdRepos3: evalStdRepos3.o stdreposutils.o stdinfo.o
# 	$(CXX) -o $@ $^ -lyaml-cpp03

# evalStdRepos3.o: evalStdRepos3.cpp stdreposutils.h stdinfo.h

printYamlFile: printYamlFile.o
	$(CXX) -o $@ $^ -lyaml-cpp03 

printYamlFile.o: printYamlFile.cpp
clean:
	rm -f getStdRepos.o eafitCVSInfo2StdInfo.o stdinfo.o stdreposutils.o evalStdRepos.o printYamlFile.o
	rm -f traerRepositorio eafitCVSInfo2StdInfo evalStdRepos evalStdRepos3 printYamlFile

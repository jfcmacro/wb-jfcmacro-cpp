all: getStdRepos eafitCVSInfo2StdInfo evalStdRepos evalStdRepos3

CXXFLAGS=-Wall

getStdRepos: getStdRepos.o stdinfo.o stdreposutils.o
	$(CXX) -o $@ $^

getStdRepos.o: getStdRepos.cpp stdinfo.h stdreposutils.h

stdreposutils.o: stdreposutils.cpp stdreposutils.h

stdinfo.o: stdinfo.cpp stdinfo.h stdreposutils.h

eafitCVSInfo2StdInfo: eafitCVSInfo2StdInfo.o
	$(CXX) -o $@ $<

eafitCVSInfo2StdInfo.o: eafitCVSInfo2StdInfo.cpp

evalStdRepos: evalStdRepos.o stdreposutils.o stdinfo.o
	$(CXX) -o $@ $^

evalStdRepos.o: evalStdRepos.cpp stdreposutils.h stdinfo.h

evalStdRepos3: evalStdRepos3.o stdreposutils.o stdinfo.o
	$(CXX) -o $@ $^

evalStdRepos3.o: evalStdRepos3.cpp stdreposutils.h stdinfo.h
clean:
	rm -f getStdRepos.o eafitCVSInfo2StdInfo.o stdinfo.o stdreposutils.o
	rm -f traerRepositorio eafitCVSInfo2StdInfo

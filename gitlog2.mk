all: gitlog2 gitResetFirstCommit gitCommitAmend gitPushForce

LDFLAGS=-lgit2

gitlog2: gitlog2.o
	${CXX} -o $@ $^ ${LDFLAGS}

gitlog2.o: gitlog2.cpp

gitResetFirstCommit: gitResetFirstCommit.o
	${CXX} -o $@ $^ ${LDFLAGS}

gitResetFirstCommit.o: gitResetFirstCommit.cpp

gitCommitAmend: gitCommitAmend.o
	${CXX} -o $@ $^ ${LDFLAGS}

gitCommitAmend.o: gitCommitAmend.cpp

gitPushForce: gitPushForce.o
	${CXX} -o $@ $^ ${LDFLAGS}

gitPushForce.o: gitPushForce.cpp

clean:
	rm -f gitlog2 gitResetFirstCommit gitCommitAmend gitPushForce
	rm -f gitlog2.o gitResetFirstCommit.o gitCommitAmend.o gitPushForce.o
	rm -f gitlog2.cpp~ gitResetFirstCommit.cpp~ gitCommitAmend.cpp~ gitPushForce.cpp~


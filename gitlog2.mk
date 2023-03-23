all: gitlog2 gitResetFirstCommit gitCommitAmend

gitlog2: gitlog2.o
	${CXX} -o $@ $^ -lgit2

gitlog2.o: gitlog2.cpp

gitResetFirstCommit: gitResetFirstCommit.o
	${CXX} -o $@ $^ -lgit2

gitResetFirstCommit.o: gitResetFirstCommit.cpp

gitCommitAmend: gitCommitAmend.o
	${CXX} -o $@ $^ -lgit2

gitCommitAmend.o: gitCommitAmend.cpp


clean:
	rm -f gitlog2 gitResetFirstCommit gitCommitAmend
	rm -f gitlog2.o gitResetFirstCommit.o gitCommitAmend.o
	rm -f gitlog2.cpp~ gitResetFirstCommit.cpp~ gitCommitAmend.cpp~

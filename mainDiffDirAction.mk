CXXFLAGS=-g
all: mainDiffDirAction

mainDiffDirAction: mainDiffDirAction.o diffDirAction.o
	${CXX} -o $@ $^

mainDiffDirAction.o: mainDiffDirAction.cpp

diffDirAction.o: diffDirAction.cpp

clean:
	rm -f mainDiffDirAction.o diffDirAction.o
	rm -f mainDiffDirAction
	rm -f mainDiffDirAction.cpp~ difDirAction.cpp~ mainDiffDirAction.mk~


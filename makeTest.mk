
all: mainTest

mainTest: mainTest.o test.o
	$(CXX) -o $@ $^ $(LDFLAGS)

mainTest.o: mainTest.cpp test.h

test.o: test.cpp test.h

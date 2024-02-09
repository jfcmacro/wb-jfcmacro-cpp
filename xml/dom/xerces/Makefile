

all: createDOMStore example01

createDOMStore: createDOMStore.o
	$(CXX) -o $@ $^ -lxerces-c

createDOMStore.o: createDOMStore.cpp

example01: example01.o
	$(CXX) -o $@ $^ -lxerces-c

example01.o: example01.cpp

clean:
	rm -f *.o createDOMStore example01

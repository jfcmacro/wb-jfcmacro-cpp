.phony: clean

all: simple

CXXFLAGS=`pkg-config gtkmm-3.0 --cflags` -std=c++11
LDFLAGS=`pkg-config gtkmm-3.0 --libs`

simple: base.o 
	$(CXX) -o $@ $(LDFLAGS) $<

base.o: base.cpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f *.o simple *.cpp~ Makefile~

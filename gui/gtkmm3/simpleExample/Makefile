.phony: clean

all: simple

CXXFLAGS=`pkg-config gtkmm-3.0 --cflags`
LDFLAGS=`pkg-config gtkmm-3.0 --libs`

simple: base.o 
	$(CXX) -o $@ $(LDFLAGS) $<

base.o: base.cpp
	$(CXX) -c $(CXXFLAGS) $<

clean:
	rm -f *.o simple *.cpp~ Makefile~

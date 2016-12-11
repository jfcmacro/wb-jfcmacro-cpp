.phony: clean

CXXFLAGS=-g `wx-config --cxxflags`
LDFLAGS=`wx-config --libs`

all: minimal

minimal: minimal.o
	$(CXX) -o $@ $^ $(LDFLAGS)

minimal.o: minimal.cpp mondrian.xpm
	$(CXX) $(CXXFLAGS) -c $< 

clean:
	rm -f *.o minimal

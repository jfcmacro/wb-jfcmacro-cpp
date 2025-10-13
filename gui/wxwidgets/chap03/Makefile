.phony: clean

CXXFLAGS= -g `wx-config --cxxflags`
LDFLAGS=`wx-config --libs`

all: minimal minimalWithoutTable fontctrl.o

minimal: minimal.o
	$(CXX) -o $@ $^ $(LDFLAGS)

minimal.o: minimal.cpp mondrian.xpm
	$(CXX) $(CXXFLAGS) -c $<

minimalWithoutTable: minimalWithoutTable.o
	$(CXX) -o $@ $^ $(LDFLAGS)

minimalWithoutTable.o: minimalWithoutTable.cpp mondrian.xpm
	$(CXX) $(CXXFLAGS) -c $< 

clean:
	rm -f *.o minimal minimalWithoutTable

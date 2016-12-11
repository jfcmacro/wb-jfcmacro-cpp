.phony: clean

CXXFLAGS=-g `wx-config --cxxflags`
LDFLAGS=`wx-config --libs`
EXECUTABLES=minimal dialog

all: $(EXECUTABLES)

minimal: minimal.o
	$(CXX) -o $@ $^ $(LDFLAGS)

minimal.o: minimal.cpp mondrian.xpm
	$(CXX) $(CXXFLAGS) -c $<

dialog: dialog.o
	$(CXX) -o $@ $^ $(LDFLAGS)

dialog.o: dialog.cpp mondrian.xpm

clean:
	rm -f *.o $(EXECUTABLES)

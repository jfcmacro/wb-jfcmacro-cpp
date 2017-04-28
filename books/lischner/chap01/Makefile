CXXFLAGS=-pedantic -std=c++11

all: list0101 list0102 list0101cl list0102cl

list0101cl: list0101.cpp
	clang++ -o $@ -pedantic -std=c++11 $<

list0102cl: list0102.cpp
	clang++ -o $@ -pedantic -std=c++11 $<



clean:
	rm -f *.o *~
	rm -f list0101 list0102

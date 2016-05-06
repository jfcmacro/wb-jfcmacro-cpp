
all:: creartuberias02 inputIncr

CXXFLAGS=-std=c++11

creartuberias02: creartuberias02.o
	$(CXX) -o $@ $<

inputIncr: inputIncr.o
	$(CXX) -o $@ $<

clean:
	rm -f inputIncr creartuberias02
	rm -f inputIncr.o creartuberias02.o

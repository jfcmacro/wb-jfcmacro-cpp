
all:: creartuberias02 inputIncr creartuberias03 inputIncr03 creartuberias04 inputIncr04

CXXFLAGS=-std=c++11

creartuberias02: creartuberias02.o
	$(CXX) -o $@ $<

inputIncr: inputIncr.o
	$(CXX) -o $@ $<

creartuberias03: creartuberias03.o
	$(CXX) -o $@ $<

inputIncr03: inputIncr03.o
	$(CXX) -o $@ $<

creartuberias04: creartuberias04.o
	$(CXX) -o $@ $<

inputIncr04: inputIncr04.o
	$(CXX) -o $@ $<

clean:
	rm -f inputIncr creartuberias02
	rm -f inputIncr.o creartuberias02.o
	rm -f inputIncr03 creartuberias03
	rm -f inputIncr03.o creartuberias03.o

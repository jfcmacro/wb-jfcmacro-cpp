all: parser

parser: parser.o
	${CXX} -o $@ $^ -lxerces-c  

parser.o: parser.cpp parser.hpp
	${CXX} -c $< -DMAIN_TEST -pedantic

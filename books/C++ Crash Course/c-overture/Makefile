all: isqrt isqrt.s iterator container_example

isqrt: isqrt.o
	${CXX} -o $@ $<

isqrt.s: isqrt.cpp
	${CXX} -O2 -S $<

isqrt.o: isqrt.cpp

iterator: iterator.o
	${CXX} -o $@ $<

iterator.o: iterator.cpp

container_example: container_example.o
	${CXX} -o $@ $<

container_example.o: container_example.cpp

clean:
	rm -f isqrt isqrt.s isqrt.o iterator.o iterator \
              container_example container_example.o
	rm -f *~ 

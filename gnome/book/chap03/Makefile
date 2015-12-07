all: helloworld

helloworld: helloworld.o
	g++ -o $@ $< `pkg-config gtk+-3.0 --libs`

helloworld.o: helloworld.cpp
	g++ -c $< `pkg-config gtk+-3.0 --cflags`

clean:
	rm *.o *~


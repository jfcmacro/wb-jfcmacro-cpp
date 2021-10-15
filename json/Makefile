
all: reader-writer

reader-writer: reader-writer.o
	${CXX} -o $@ $^ -ljsoncpp -std=c++11

reader-writer.o: reader-writer.cpp
	${CXX} -c $< 

clean:
	rm -f reader-writer *.o *.*~ *~

CXXFLAGS=
LDFLAGS=-lossp-uuid++

all: uuid

uuid: uuid.o
	${CXX} -o $@ $^ ${LDFLAGS}

uuid.o: uuid.cpp

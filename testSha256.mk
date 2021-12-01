all: testSha256 testSha256_2 testSha256_3

LDFLAGS=-lcrypto -lssl
CXXFLAGS=-g

testSha256: testSha256.o sha256base64.o
	${CXX} -o $@ $^ ${LDFLAGS}

testSha256_2: testSha256_2.o sha256base64.o
	${CXX} -o $@ $^ ${LDFLAGS}

testSha256_3: testSha256_3.o
	${CXX} -o $@ $^

sha256base64.o: sha256base64.cpp



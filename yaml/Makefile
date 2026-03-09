all: readFileExample readFileBankerAlgoExample

readFileExample: readFileExample.o
	${CXX} -o $@ $< -lyaml-cpp

readFileExample.o: readFileExample.cpp
	${CXX} -c $<

readFileBankerAlgoExample: readFileBankerAlgoExample.o
	${CXX} -o $@ $< -lyaml-cpp

readFileBankerAlgoExample.o: readFileBankerAlgoExample.cpp
	${CXX} -c $<

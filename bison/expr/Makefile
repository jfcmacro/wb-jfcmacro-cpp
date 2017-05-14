all: calc++

calc++: calc++.o calc++-driver.o calc++-lexer.o calc++-parser.o
	$(CXX) -o $@ $^

calc++.o: calc++.cpp calc++-driver.hh

calc++-driver.o: calc++-driver.cpp calc++-parser.hh

calc++-lexer.cpp: calc++-lexer.ll
	flex --c++ --outfile=$@  $<

calc++-parser.cpp calc++-parser.hh: calc++-parser.yy
	bison --language=c++ --defines=calc++-parser.hh --output=calc++-parser.cpp $<

clean:
	rm -f *.o
	rm -f calc++-lexer.cpp calc++-parser.cpp calc++-parser.hh
	rm -f *~
	rm -f location.hh position.hh stack.hh

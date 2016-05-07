
all: getuid libpasswd.a

getuid: main.o
	g++ -o $@ $< -L/home/fcardona/workbench/wb-jfcmacro/trunk/Programas/c++/static -lpasswd -lstdc++

main.o: main.cpp passwd.h
	g++ -c -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -Wall -fPIC -fexceptions -g $<

libpasswd.a: import.o getuid.o
	ar -r $@ $^

import.o: import.cpp passwd.h
	g++ -c -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -Wall -fPIC -fexceptions -g $<

getuid.o: getuid.cpp passwd.h
	g++ -c -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -Wall -fPIC -fexceptions -g $<

clean:
	rm -f getuid *.o *.*~ 

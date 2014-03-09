PLATFORM = LINUX
COMPILER = g++
CXXFLAGS = -w -O
CFLAGS = -w -O
LDFLAGS =
INCLUDES = -I. -I${XERCESCROOT}/include
LIB_DIR = ${XERCESCROOT}/lib
LIBNAME = xerces-c
THISLIB=${LIB_DIR}/${LIBNAME}
VER=
LIBRARY_NAMES = -l${LIBNAME}${VER}
LIBRARY_SEARCH_PATHS=-L${LIB_DIR}
CMP= -c ${CXXFLAGS}
CC= g++ -c -D${PLATFORM} -D_REENTRANT -fpic
LINK =  g++ -D${PLATFORM} -fpic ${LDFLAGS}
PLATFORM_LIB_LINK_OPTIONS=-L/usr/lib -L/usr/local/lib -L${LIB_DIR}
EXTRA_LINK_OPTIONS=-lc
SHLIBSUFFIX=.so
OBJS = Parser.o MySaxHandler.o

all: Parser 

Parser: ${OBJS}
	${LINK} -o $@ ${PLATFORM_LIB_LINK_OPTIONS} ${LIBRAY_SEARCH_PATHS} ${LIBRARY_NAMES} ${OBJS} 

Parser.o: Parser.C 
	${CC} ${CMP} $(INCLUDES) -o Parser.o Parser.C

MySaxHandler.o: MySaxHandler.C
	${CC} ${CMP} $(INCLUDES) -o MySaxHandler.o MySaxHandler.C

clean:
	rm -f Parser.o MySaxHandler.o Parser *.*~

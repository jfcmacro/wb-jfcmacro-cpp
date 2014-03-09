
KDEDIR=/usr
QTDIR=/usr/lib/qt-3.3

all: khello khello2

khello: khello.o
	g++ -o $@ $< -L$KDEDIR/lib -L$QTDIR/lib -lkdeui -lkdecore -ldl

khello.o: khello.cpp
	g++ -c -I${KDEDIR}/include/kde -I${QTDIR}/include $<

khello2: khello2.o
	g++ -o $@ $< -L${KDEDIR}/lib -L${QTDIR}/lib -lkdeui -lkdecore -ldl

khello2.o: khello2.C
	g++ -c -I${KDEDIR}/include/kde -I${QTDIR}/include $< 
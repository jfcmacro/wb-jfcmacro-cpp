#include <iostream>
#include <stdlib.h>

using namespace std;

void
funcion(int& x, int y) {
	x = 0;
	y = 0;
}

int
main() {

	int x = 1;
	int y = 2;

	cout << "x: " << x << " y: " << y << endl;
	funcion(x,y);
	cout << "x: " << x << " y: " << y << endl;

	::exit(0);
}

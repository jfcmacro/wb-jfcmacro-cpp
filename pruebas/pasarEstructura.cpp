#include <iostream>

using namespace std;

struct Nuevo {
	int x;
	int y;
	int z;
	int w;
};

void
funcion(struct Nuevo nuevo)  {

	cout << nuevo.x << "  " << nuevo.y  << endl;
}

int
main() {

	struct Nuevo nuevo;

	nuevo.x = 10;
	nuevo.y = 20;

	funcion(nuevo);

	return 0;
}
	

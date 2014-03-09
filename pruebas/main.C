#include "A.h"
#include <iostream>

int
main()
{
	A a(10);

	cout << a.retornarValor() << endl;
	int w;
	cin >> w;
	a.ponerValor(w);
	cout << a.retornarValor() << endl;
}

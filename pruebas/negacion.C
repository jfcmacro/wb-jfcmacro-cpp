#include <iostream>

int
main() {

	unsigned short x = 0x0;

	x = ~x;

	x >>=1;

	x = ~x;

	cout << hex << x << endl;
}

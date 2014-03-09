#include <iostream>

using namespace std;

int
main(int argc, char *argv[]) {

	unsigned short valor1 = 0xBC;
	unsigned short valor2 = 0xF1;

	cout << "valor1 " << hex << valor1 << " valor2: " << hex << valor2 << endl;
	cout << "valor1 & valor2 " << hex << (valor1 & valor2) << endl;
	cout << "valor1 | valor2 " << hex << (valor1 | valor2) << endl;
	cout << "!valor1 " << hex << !valor1 << endl;
	cout << "~valor1 " << hex << ~valor1 << endl;

	return 0;

}

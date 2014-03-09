#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {


	char *s;
	char *k;

	s = new char[strlen("Hola Mundo") + 1];
	k = "Hola Mundo";
	strcpy(s, "Hola Mundo");
	s[0] = 'h';
	s[5] = 'm';
	cout << s << " " << k << endl;
	printf("%x %x\n", s, k);

}

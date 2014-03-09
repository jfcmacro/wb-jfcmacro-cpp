#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int
main() {

	string s("Hola Mundo Cruel, estoy viendo sistemas operativos");
	char *cadena;
	char *token;

	cadena = (char *) s.c_str();

	token = strtok(cadena, " ");
	do { 

		printf("%s\n", token);


	} while ((token = strtok(NULL, " ")) != NULL);
}

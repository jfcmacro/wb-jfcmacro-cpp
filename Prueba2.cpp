#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

const char message1[] = "Error abriendo fichero";
const char message2[] = "total: ";
const char total[] = "Total: ";
const int FILESIZE = 1024;

int
main(int argc, char *argv[]) {

  int fd = open("prueba1.txt", O_RDONLY);

  if (fd == -1) {
    write(1, message1, strlen(message1));
    _exit(1);
  }

  char buffer[FILESIZE + 1];

  int tam = read(fd, buffer, FILESIZE);
 
  if (tam != 0) {
    int valor = 0;
    char *p = strtok(buffer, " \n");
    while (p != nullptr) {
      int i = atoi(p);
      valor += i;
      p = strtok(nullptr, " \n");
    }
    write(1, message2, strlen(message2));
    char bufferEntero[10];
    sprintf(bufferEntero, "%d\n", valor);
    write(1, bufferEntero, strlen(bufferEntero));
  }

  close(fd);

  return 0;
}

#include "lista.h"
#include <stdlib.h>

ListaInt*
crearListaInt() {
  return malloc(sizeof(ListaInt));
}

otrafuncion(ListaInt* lista) {
  lista->valor = 0;
  lista->sig = NULL;
}

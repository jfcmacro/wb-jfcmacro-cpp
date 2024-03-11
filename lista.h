#pragma once

typedef ListaInt struct ListaInt {
  int valor;
  struct ListaInt* sig;
};

ListaInt* crearListaInt();
ListaInt* adicionarInt(ListaInt* lista, int valor); 

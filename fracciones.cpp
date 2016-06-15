#include <iostream>
#include <fstream>

using namespace std;


// Calcula el denominador
int denominador(char c) {
  return c - '0';
}

// Calcula la posicion de un denominador en el arreglo
int posicion(char c) {
  return denominador(c) - 1;
}

int
main(void) {

  ofstream ofs("salida_fracciones.txt", ios::trunc);

  const int TOTAL_FRACCIONES = 9;

  int fracciones[9] = { 0, 0, 0,
			0, 0, 0,
			0, 0, 0
  };
  int unidad = 0;
  char valor;

  while (cin >> valor) {
    ofs << valor << endl;
    fracciones[posicion(valor)]++;
    if (fracciones[posicion(valor)] == denominador(valor)) {
      unidad++;
      fracciones[posicion(valor)] = 0;
    }
  }

  int denominador = 1;
  int numerador = 1;
  for (int i = 0; i < TOTAL_FRACCIONES; ++i) {
    if (fracciones[i] != 0) {
      numerador *= fracciones[i];
      denominador *= (i+1);
    }
  }

  cout << unidad << ':';
  ofs << unidad << ":";
  
  if (!cout) ofs << "Tenemos problemas Houston" << endl;

  for (int i = 0; i < TOTAL_FRACCIONES; ++i) {
    cout << fracciones[i];
    ofs << fracciones[i];
    
    if (!cout) ofs << "Tenemos problemas Houston" << endl;
  }

  cout << ':' << numerador << '|' << denominador;
  ofs << ':' << numerador << '|' << denominador;

  
  if (!cout) ofs << "Tenemos problemas Houston" << endl;

  return 0;
}

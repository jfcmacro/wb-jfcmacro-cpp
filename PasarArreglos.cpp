#include <iostream> 

using namespace std;

int mayor(int **p, int len, int heig) {

   int mayor = 0;
   for (int i = 0; i < len; i++) {
      for (int j =0; j < heig; j++) {
         if (p[i][j] >= mayor) {
            mayor = p[i][j];
         }
      }
   }
   return mayor;
}


int mayor2(int *p[], int len, int heig) {

   int mayor = 0;
   for (int i = 0; i < len; i++) {
      for (int j =0; j < heig; j++) {
         if (p[i][j] >= mayor) {
            mayor = p[i][j];
         }
      }
   }
   return mayor;
}

void imprimirMatriz(int *p[], int len, int heig) {

   for (int i = 0; i < len; i++) {
      for (int j =0; j < heig; j++) {
	cout << '\t' << p[i][j];
      }
      cout << endl;
   }
   return;
}

int
main(int argc, char *argv[]) {
  
   int **p;
   int len, heig;

   cin >> len >> heig; 

   cout << "Len: " << len << " height: " << heig << endl;
   p = new int*[len];
   for (int i = 0; i < len; i++) {
      p[i] = new int[heig];
      for (int j = 0; j < heig; j++) {
         cin >> p[i][j];
         cout << p[i][j] << endl;
      } 

   }

   cout << "Imprime matriz" << endl;
   imprimirMatriz(p,len,heig);
   cout << "Prueba de imprimir matriz2" << endl;
   cout << sizeof(p[0][0]) << endl;
   imprimirMatriz2(p);
   cout << "Inicia busqueda" << endl;

   cout << mayor(p, len, heig) << endl;
   cout << mayor2(p, len, heig) << endl;
   return 0;
}

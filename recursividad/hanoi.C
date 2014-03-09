#include <iostream>
#include <stdlib.h>

void
hanoi(int n, int i, int j) {

  if (n == 1) 
    cout << "Pase un disco de " << i <<  " a " << j << endl;
  else {

    int k = 6 - i - j;
    hanoi(n - 1, i, k);
    hanoi(1, i, j);
    hanoi(n - 1, k, j);
  }
}

int
main(int argc, char *argv[])
{
  int n = 3;

  if (argc > 1) 
    n = ::strtol(argv[1], (char **) NULL, 10);


  cout << "Hanoi de " << n << endl;
  hanoi(n, 1, 3);

}
    

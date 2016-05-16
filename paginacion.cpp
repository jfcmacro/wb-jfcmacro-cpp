#include <iostream>

int
main() {

  int nf;

  cin >> nf;

  int *afr[] = new int[nf];
  int *frafr[] = new int[nf];

  for (int i = 0; i < nf; ++i) {

    afr[i] = -1;
    frafr[i] = 0;
  }

  int pg;
  
  while (cin > pg) {

    int j = 0;
    for (j = 0; j < nf; ++j) {

      if (afr[j] == pg) break;
    }

  }
}

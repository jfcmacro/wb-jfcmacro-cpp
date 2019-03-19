#include <iostream>

using namespace std;

int
main() {

  int n;
  int m;

  cin >> n >> m;

  int matriz[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matriz[i][j] = i * j;
      cout << "matriz[" << i << "][" << j << "]=" << matriz[i][j]
	   << endl;
      
    }
  }

  

  return 0;
}

#include<iostream>
#include<vector>


using namespace std;

int
main() {

  int n;

  cout << "Digite el numero de elementos: ";
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < v.size(); i++) {
    cin >> v[i];
  }

  for (int i = 0; i < v.size(); i++) {
    cout << "v[" << i << "]=" << v[i] << endl;
  }

  return 0;
}


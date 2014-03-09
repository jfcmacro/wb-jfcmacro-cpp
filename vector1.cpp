#include<iostream>
#include<vector>
// #include<iterator>

using namespace std;

int
main() {

  int n;

  cout << "Digite el numero de elementos: ";
  cin >> n;

  vector<int> v(n);
 
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cin >> *it;
  }

  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    if (*it == -1) {
      v.erase(it);
    }
  }

  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << endl;
  }

  return 0;
}


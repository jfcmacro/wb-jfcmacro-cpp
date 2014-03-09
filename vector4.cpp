#include <iostream>
#include <vector>

using namespace std;


int
main() {

  int n;

  cin >> n;

  vector<int>  v(n);

  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cin >> *it;
  }

  for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
    cout << *it << endl;
  }

  return 0;
}

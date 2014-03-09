#include <iostream>
#include <vector>

using namespace std;

int
main(void) {

  vector<int> v(20);
  
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;

  pair<int, vector<int>& > p(3, v);
  vector<int> &vp = p.second;
  for (int i = 0; i < p.first; i++) {
    cout << vp[i] << endl;
  }
  v[0] = 10;
    for (int i = 0; i < p.first; i++) {
    cout << vp[i] << endl;
  }
  return 0;
}

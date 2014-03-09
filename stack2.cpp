#include <iostream>
#include <vector>

using namespace std;

int
main() {
  int n;

  cin >> n;

  vector<int>  v(n);
  int val;
  cin >> val;
  v.push_back(val);
  cin >> val;
  v.push_back(val);
  cin >> val;
  v.push_back(val);

  cout << v[v.size() - 1] << endl;
  v.pop_back();
  cout << v[v.size() - 1] << endl;

  return 0;
}

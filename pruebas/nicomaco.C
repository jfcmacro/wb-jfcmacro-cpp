#include <iostream>

using namespace std;

int
main() {

	int n;
	
	cin >> n;

	for (int i = 0, j = 1; i < n; i++) {
		int sum;

		for (int k = 0, sum = 0; k < (i + 1) * 2; k += 2, j += 2) {

			sum += j;
		}

		cout << "n: " << n << " es: " << sum << endl;
	}
}

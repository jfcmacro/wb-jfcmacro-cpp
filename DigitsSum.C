#include <iostream>
#include <map>

using namespace std;

long long f(int b) {
	if (b == 0) return 0;
	long long ans = 0;
	for (int p = 0; p <= 9 and p <= b; ++p) {
            int remain = (b - p) / 10;
            ans += p * (remain + 1) * f (remain);
	}
	return ans;
}

int
main() {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 & b == 0) break;
                cout << f(b) - f(a -1) << endl;
	}
	return 0;
}

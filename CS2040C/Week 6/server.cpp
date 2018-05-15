// Server
#include <bits/stdc++.h>
using namespace std;

int main() {		// O(n)
	int n, T, val, count = 0;
	bool b = 1;
	cin >> n >> T;
	for (int i=0; (i<n) && b ; i++) {
		cin >> val;
		if (T - val >= 0) {
			T -= val;
			count++;
		}
		else
			b = 0;
	}
	cout << count << endl;
	return 0;
}
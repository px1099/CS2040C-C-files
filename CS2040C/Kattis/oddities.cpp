// oddities
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, x;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		cout << x << " is " << ((x%2==0) ? "even" : "odd") << endl;
	}
	return 0;
}
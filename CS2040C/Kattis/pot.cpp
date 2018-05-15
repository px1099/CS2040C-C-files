// pot
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, p, x = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a;
		p = a%10;
		a /= 10;
		x += pow(a,p);
	}
	cout << x << endl;
	return 0;
}
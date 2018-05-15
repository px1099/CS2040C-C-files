// nastyhacks
#include <bits/stdc++.h>
using namespace std;
int main() {
	int r,e,c,x,n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> r >> e >> c;
		x = (e - c) - r;
		if (x == 0)
			cout << "does not matter";
		else if (x > 0)
			cout << "advertise";
		else
			cout << "do not advertise";
		cout << endl;
	}
	return 0;
}
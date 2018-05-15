// Booking a room
#include <bits/stdc++.h>
using namespace std;

int main() {
	int r,n,i,x, arr[100] = {0};
	cin >> r >> n;
	for (i=0;i<n;i++) {
		cin >> x;
		arr[x-1] = 1;
	}
	x = -1;
	for (i=0;i<r;i++) {
		if (arr[i] == 0) {
			x = i+1;
			cout << x << endl;
			break;
		}
	}
	if (x == -1)
		cout << "too late" << endl;
	return 0;
}
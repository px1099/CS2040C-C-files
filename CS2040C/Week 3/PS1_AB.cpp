#include <bits/stdc++.h>
#define MAXSIZE 3000
using namespace std;

void sortArray (unsigned long long a[], int i) {	// O(N)
	unsigned long long temp = a[i];
	while (a[i-1]>temp && i>0) {
		a[i] = a[i-1];
		i--;
	}
	a[i] = temp;
}

unsigned long long median(unsigned long long a[], int n) {	// O(1)
	if (n%2)
		return a[n/2];
	else
		return (a[n/2-1]+a[n/2])/2;
}

int main() {	// O(TC*N^2)
	unsigned long long a[MAXSIZE] = {0};
	unsigned long long medsum;
	int TC, N, i, j, k;
	cin >> TC;
	for (k=0; k<TC; k++) {
		cin >> N;
		medsum = 0;
		for (i=0;i<N;i++) {
			cin >> a[i];
			sortArray(a,i);
			medsum += median(a,i+1);
		}
		cout << medsum << endl;
	}
	return 0;
}
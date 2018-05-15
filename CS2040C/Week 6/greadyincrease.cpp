// Greedily Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

int main() { 		// O(n)
	vector<int> A;
	vector<int> B;
	int n, size, val, j=1;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> val;
		A.push_back(val);
	}
	val = A[0];
	B.push_back(val);
	while (j < n) {
		if (A[j] > val) {
			val = A[j];
			B.push_back(val);
		}
		j++;
	}
	size = B.size();
	cout << size << endl;
	for (int i=0; i<size; i++)
		cout << B[i] << " ";
	cout << endl;
	return 0;
}
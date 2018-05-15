// Mock PE3
#include <bits/stdc++.h>
using namespace std;

int main() {
	multiset<int> A;
	int N, Q, val;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> val;
		A.insert(val);
	}
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> val;
		if (val>0)
			A.insert(val);
		else if (val<0) {
			val = (-1)*val;
			auto it = A.find(val);
			if (it != A.end())
				A.erase(it);
		} else {
			int min = *(A.begin());
			int max = *(A.rbegin());
			cout << max - min << endl;
		}
	}
	return 0;
}
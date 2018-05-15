// synchronizing lists
#include <bits/stdc++.h>
using namespace std;

int main() { 		// O(TC*n*log(n))
	int n, value;
	vector<int> B,result;
	vector<pair<int,int>> A;
	while(cin >> n, n!=0) {
		A.clear();
		B.clear();
		result.clear();
		for (int i=0; i<n; i++) {
			cin >> value;
			A.push_back(make_pair(value,i));
		}
		for (int i=0; i<n; i++) {
			cin >> value;
			B.push_back(value);
		}
		sort(A.begin(),A.end(),[](pair<int,int> a, pair<int,int> b) {
			return (get<0>(a)) < (get<0>(b));
		});
		sort(B.begin(),B.end());
		result.reserve(n);
		for (int i=0; i<n; i++)
			result[get<1>(A[i])] = B[i];
		for (int i=0; i<n; i++)
			cout << result[i] << endl;
		cout << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<unsigned long long,vector<unsigned long long>,less<unsigned long long>> left;
	priority_queue<unsigned long long,vector<unsigned long long>,greater<unsigned long long>> right;
	unsigned long long medsum, value;
	int TC, N = 0; 
	cin >> TC;
	for (int k=0; k<TC; k++) {
		while (!left.empty())
			left.pop();
		while (!right.empty())
			right.pop();
		cin >> N;
		cin >> medsum;
		left.push(medsum);
		for (int i=1; i<N; i++) {
			cin >> value;
			if (value <= left.top()) {
				left.push(value);
				if (left.size() - right.size() >= 2) {
					right.push(left.top());
					left.pop();
				}
			} else {
				right.push(value);
				if (right.size() - left.size() >= 1) {
					left.push(right.top());
					right.pop();
				}
			}
			if (left.size() == right.size())
				medsum += (left.top() + right.top())/2;
			else
				medsum += left.top();
		}
		cout << medsum << endl;
	}
	cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." << endl;
	return 0;
}
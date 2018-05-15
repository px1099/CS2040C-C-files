// PS2B - Pham Quang Minh
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, command, val, sum;
	bool isSta, isQue;
	stack<int> s;
	queue<int> q;
	while (cin >> n, n != 0) {
		while (!s.empty())
			s.pop();
		while (!q.empty())
			q.pop();
		isSta = 1;
		isQue = 1;
		for (int i=1; i<=n; i++) {
			cin >> command >> val;
			if (command == 1) {
				if (isSta)
					s.push(val);
				if (isQue)
					q.push(val);
			} else {
				if (isSta) {
					if ((!s.empty()) && (s.top() == val))
						s.pop();
					else
						isSta = 0;
				}
				if (isQue) {
					if ((!q.empty()) && (q.front() == val))
						q.pop();
					else
						isQue = 0;
				}
			}
		}
		sum = isSta + isQue;
		if (sum == 0) 
			cout << "impossible\n";
		else if (sum > 1)
			cout << "not sure\n";
		else if (isSta) 
			cout << "stack\n";
		else
			cout << "queue\n";
	}
	return 0;
}
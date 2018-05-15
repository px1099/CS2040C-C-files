// PS2C - Pham Quang Minh
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, command, val, sum;
	bool isSta, isQue, isPrq;
	stack<int> s;
	queue<int> q;
	priority_queue<int> p;
	while (cin >> n, n != 0) {
		while (!s.empty())
			s.pop();
		while (!q.empty())
			q.pop();
		while (!p.empty())
			p.pop();
		isSta = 1;
		isQue = 1;
		isPrq = 1;
		for (int i=1; i<=n; i++) {
			cin >> command >> val;
			if (command == 1) {
				if (isSta)
					s.push(val);
				if (isQue)
					q.push(val);
				if (isPrq)
					p.push(val);
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
				if (isPrq) {
					if ((!p.empty()) && (p.top() == val))
						p.pop();
					else
						isPrq = 0;
				}
			}
		}
		sum = isSta + isQue + isPrq;
		if (sum == 0) 
			cout << "impossible\n";
		else if (sum > 1)
			cout << "not sure\n";
		else if (isSta) 
			cout << "stack\n";
		else if (isQue)
			cout << "queue\n";
		else 
			cout << "priority queue\n";
	}
	return 0;
}
// PS2A - Pham Quang Minh
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, command, val;
	bool isSta;
	stack<int> s;
	while (cin >> n, n != 0) {
		while (!s.empty())
			s.pop();
		isSta = 1;
		for (int i=1; i<=n; i++) {
			cin >> command >> val;
			if (command == 1) {
				if (isSta)
					s.push(val);
			} else {
				if (isSta) {
					if ((!s.empty()) && (s.top() == val))
						s.pop();
					else
						isSta = 0;
				}
			}
		}
		if (isSta == 0) 
				cout << "impossible\n";
			else
				cout << "stack\n";
	}
	return 0;
}
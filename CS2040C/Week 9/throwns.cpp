// throwns
#include <bits/stdc++.h>
using namespace std;

int main() {
	//	freopen("in.txt", "r", stdin);
	stack<int> STK;
	int n, k;
	cin >> n >> k;
	string command;
	for (int i=0; i<k; i++) {
		cin >> command;
		if (command != "undo") {
			istringstream iss(command);
			int value;
			iss >> value;
			STK.push(value);
		} else {
			cin >> command;
			istringstream iss(command);
			int number;
			iss >> number;
			for (int j=0; j<number; j++)
				STK.pop();
		}
	}
	int result = 0;
	while (STK.empty() != 1) {
		result += STK.top() % n;
		STK.pop();
	}
	result = result % n;
	if (result < 0)
		result += n;
	cout << result;
	return 0;
}
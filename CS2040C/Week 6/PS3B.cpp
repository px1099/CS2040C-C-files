// PS3B
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,string> woman;

class Hospital {
private:
	priority_queue<woman> data;
	int index;
public:
	Hospital() {
		index = 0;
	}
	void ArriveAtHospital(string name, int val) {
		data.push(make_tuple(val, -1*index, name));
		++index;
	}
	void GiveBirth() {
		data.pop();
	}
	string Query() {
		if (data.size() == 0)
			return "The delivery suite is empty";
		else
			return get<2>(data.top());
	}
};

int main() {
	Hospital delivery;
	string name;
	int n, command, val;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> command;
		if (command == 3)
			cout << delivery.Query() << endl;
		else {
			cin >> name;
			if (command == 2)
				delivery.GiveBirth();
			else {
				cin >> val;
				delivery.ArriveAtHospital(name, val);
			}
		}
	}
	return 0;
}
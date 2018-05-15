// PS3A
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,string> woman;

class Hospital {
private:
	vector<woman> data;
	int size;
	int index;
public:
	Hospital() {
		size = 0;
		index = 0;
	}
	void ArriveAtHospital(string name, int val) {
		data.push_back(make_tuple(val, -1*index, name));
		++size;
		++index;
		for (int i=size-1; i>0 && data[i]<data[i-1]; --i)
			swap(data[i],data[i-1]);
	}
	void UpdateDilation(string name, int val) {
		for (int i=0; i<size; i++) {
			if (get<2>(data[i]) == name) {
				get<0>(data[i]) += val;
				for (int j=i+1; j<size && data[j]<data[j-1]; j++)
					swap(data[j], data[j-1]);
				break;
			}
		}
	}
	void GiveBirth(string name) {
		for (int i=0; i<size; i++) {
			if (get<2>(data[i]) == name) {
				data.erase(data.begin() + i);
				--size;
				break;
			}
		}
	}
	string Query() {
		if (size == 0)
			return "The delivery suite is empty";
		else
			return get<2>(data[size-1]);
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
				delivery.GiveBirth(name);
			else {
				cin >> val;
				if (command == 1)
					delivery.UpdateDilation(name, val);
				else
					delivery.ArriveAtHospital(name, val);
			}
		}
	}
	return 0;
}
// PS3C
#include <bits/stdc++.h>
#define UMMAXSIZE 491531
#define PQMAXSIZE 1000010
using namespace std;
typedef tuple<int,int,string> woman;
typedef tuple<int,int> dilation;

// Class of container used to store patients data
class Hospital {
private:
	unordered_map<string,dilation> tab;	// use names as keys to check values
	priority_queue<woman> data;			// sort: dilation -> index -> name
	int index;
public:
	// Create and initialize storage (O(1))
	Hospital() {
		tab.rehash(UMMAXSIZE);
		index = 0;
	}
	// Insert new element in priority_queue and unordered_map (O(log(N)))
	void ArriveAtHospital(string name, int val) {
		tab[name] = make_tuple(val, index);
		data.push(make_tuple(val, -1*index, name));
		++index;
	}
	// Update dilation in unordered_map. Insert updated element in priority_queue (O(log(N)))
	void UpdateDilation(string name, int val) {
		get<0>(tab[name]) += val;
		data.push(make_tuple(get<0>(tab[name]), -1*get<1>(tab[name]), name));
	}
	// Delete element in unordered_map. Element in priority_queue will be deleted in Query() (O(1))
	void GiveBirth(string name) {
		tab.erase(name);
	}
	// If data.top() does not exist in tab or is not updated, delete it. 
	// Do that until we get a legitimate data.top()
	// This is O(N*log(N)), but the total of all Query() called will be O(N*log(N)) too.
	string Query() {
		if (tab.size() == 0)
			return "The delivery suite is empty";
		else {
			int val = get<0>(data.top());
			string name = get<2>(data.top());
			while((tab.find(name) == tab.end()) || (get<0>(tab[name]) != val)) {
				data.pop();
				val = get<0>(data.top());
				name = get<2>(data.top());
			}
			return name;
		}
	}
};

// Time complexity: O((CMD+N)*log(N))
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen("in.txt", "r", stdin);
	// clock_t start, finish;
	// start = clock();
	
	Hospital delivery;
	string name;
	int CMD, command, val;
	cin >> CMD;
	for (int i=0; i<CMD; i++) {
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
	cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." << endl;
	// finish = clock();
	// cout << "Running time = " << ((double) ((finish-start)/CLOCKS_PER_SEC)) << endl;
	return 0;
}
// PS3D
#include <bits/stdc++.h>
#define UMMAXSIZE 10
#define PQMAXSIZE 50
using namespace std;
typedef tuple<int,int,string> woman;
typedef tuple<int,int> dilation;

// PQ implementation
class Prq {
private:
	woman arr[PQMAXSIZE];
	int size;
public:
	Prq() {
		size = 0;
		cout << "pq implemented\n";
	}
	bool empty() {
		return !size;
	}
	void clear() {
		size = 0;
	}
	woman top() {
		return arr[1];
	}
	void push(woman val) {
		size += 1;
		arr[size] = val;
		for (int i=size; (i>1) && (arr[i] > arr[i/2]); i/=2) {
			woman temp = arr[i/2];
			arr[i/2] = arr[i];
			arr[i] = temp;
		}
	}
	void pop() {
		bool sorted = 0;
		int i=1;
		arr[1] = arr[size];
		size -= 1;
		while (!sorted) {
			woman left = (i*2 <= size)?(arr[i*2]):(make_tuple(-1,0,"0"));
			woman right = (i*2+1 <= size)?(arr[i*2+1]):(make_tuple(-1,0,"0"));
			if (arr[i] < max(left,right)) {
				woman temp = arr[i];
				if (left > right) {
					arr[i] = arr[i*2];
					arr[i*2] = temp;
					i = i*2;
				} else {
					arr[i] = arr[i*2+1];
					arr[i*2+1] = temp;
					i = i*2+1;
				}
			} else
				sorted = 1;
		}
	}
};

// UM implementation
class vertex {
public:
	string key;
	dilation item;
	vertex* next;
	vertex* previous;
};

class Dll {
private:
	vertex* head;
	vertex* tail;
	int size;
public:
	Dll() {
		head = NULL;
		tail = NULL;
		size = 0;
		cout << "dll implemented\n";
	}
	void push_back(string k, dilation v) {
		vertex* vtx = new vertex();
		vtx->item = v;
		vtx->key = k;
		vtx->previous = tail;
		tail->next = vtx;
		tail = vtx;
		if (head == NULL)
			head = vtx;
		size += 1;
	}
	vertex* get(string k) {
		vertex* ptr = head;
		while ((ptr != NULL) && (ptr->key != k))
			ptr= ptr->next;
		return ptr;
	}
	void remove(string k) {
		vertex* del = get(k);
		vertex* pre = del->previous;
		vertex* aft = del->next;
		if ((pre==NULL) && (aft==NULL)) {
			head = NULL;
			tail = NULL;
		}
		else if ((pre==NULL) && (aft!=NULL)) {
			aft->previous = NULL;
			head = aft;
		}
		else if ((pre!=NULL) && (aft==NULL)) {
			pre->next = NULL;
			tail = pre;
		} else {
			pre->next = aft;
			aft->previous = pre;
		}
		delete del;
		size -= 1;
	}
};

int h(string s) {
	int result = 0;
	for(int i=0; i<s.size(); i++) {
		result += (((int)(s[i] - 'A'))*((int) pow(26,i)) % UMMAXSIZE);
		result = result % UMMAXSIZE;
	}
	return result;
}

class Um {
public:
	Dll bucket[UMMAXSIZE];
	int size;
	Um() {
		size = 0;
		cout << "um implemented\n";
	}
	bool empty() {
		return !size;
	}
	void insert(string key, dilation item) {
		(bucket[h(key)]).push_back(key, item);
		size += 1;
	}
	vertex* access(string key) {
		return (bucket[h(key)]).get(key);
	}
	void erase(string key) {
		(bucket[h(key)]).remove(key);
		size -= 1;
	}
	void update(string key, int value) {
		get<0>((access(key))->item) += value;
	}
};

// Class of container used to store patients data
class Hospital {
private:
	Um tab;				// use names as keys to check values
	Prq data;			// sort: dilation -> index -> name
	int index;
public:
	// Create and initialize storage (O(1))
	Hospital() {
		index = 0;
	}
	// Insert new element in pq and um (O(log(N)))
	void ArriveAtHospital(string name, int val) {
		tab.insert(name, make_tuple(val, index));
		data.push(make_tuple(val, -1*index, name));
		++index;
	}
	// Update dilation in um. Insert updated element in pq (O(log(N)))
	void UpdateDilation(string name, int val) {
		tab.update(name, val);
		data.push(make_tuple(get<0>((tab.access(name))->item), -1*get<1>((tab.access(name))->item), name));
	}
	// Delete element in um. Element in pq will be deleted in Query() (O(1))
	void GiveBirth(string name) {
		tab.erase(name);
	}
	// If data.top() does not exist in tab or is not updated, delete it. 
	// Do that until we get a legitimate data.top()
	// This is O(N*log(N)), but the total of all Query() called will be O(N*log(N)) too.
	string Query() {
		if (tab.size == 0)
			return "The delivery suite is empty";
		else {
			int val = get<0>(data.top());
			string name = get<2>(data.top());
			while((tab.access(name) == NULL) || (get<0>((tab.access(name))->item) != val)) {
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
	freopen("in.txt", "r", stdin);
	clock_t start, finish;
	start = clock();
	
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
	finish = clock();
	cout << "Running time = " << ((double) ((finish-start)/CLOCKS_PER_SEC)) << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef int DLL_Type;

class DLL {
private:
	// Vertex structure
	struct Vertex {
		DLL_Type item;
		Vertex* next;
		Vertex* prev;
	};
	
	// Class elements
	Vertex* head;
	Vertex* tail;
	int num_elements;

public:
	// Constructor
	DLL() {			// O(1)
		head = NULL;
		tail = NULL;
		num_elements = 0;
	}
	
	// Capacity functions
	bool empty() {	// O(1)
		return !num_elements;
	}
	int size() {	// O(1)
		return num_elements;
	}
	
	// Iterator functions
	Vertex* get_head() {	// O(1)
		return head;
	}
	Vertex* get_tail() {	// O(1)
		return tail;
	}
	Vertex* get_element(int i) {	// O(N)
		if ((i>=0) && (i<num_elements)) {
			if (i<=num_elements/2) {
				Vertex* ptr = head;
				for (int k=0; k<i; k++)
					ptr = ptr->next;
				return ptr;
			} else {
				Vertex* ptr = tail;
				for (int k=num_elements-1; k>i; k--)
					ptr = ptr->prev;
				return ptr;
			}
		}
		else
			return NULL;
	}
	
	// Access functions
	DLL_Type* access_front() {	// O(1)
		return &(head->item);
	}
	DLL_Type* access_back() {	// O(1)
		return &(tail->item);
	}
	DLL_Type* access_element(int i) {	// O(N)
		if ((i>=0) && (i<num_elements)) {
			Vertex* ptr = get_element(i);
			return &(ptr->item);
		}
		else
			return NULL;
	}
	
	// Read functions
	DLL_Type front() {	// O(1)
		return head->item;
	}
	DLL_Type back() {	// O(1)
		return tail->item;
	}
	DLL_Type read_element(int i) {	// O(N)
		if ((i>=0) && (i<num_elements)) {
			Vertex* ptr = get_element(i);
			return ptr->item;
		}
	}
	
	// Insert functions
	void push_front(DLL_Type data) {	// O(1)
		Vertex* vtx = new Vertex();
		vtx->item = data;
		vtx->prev = NULL;
		vtx->next = head;
		if (head != NULL)
			head->prev = vtx;
		head = vtx;
		if (tail == NULL)
			tail = vtx;
		num_elements += 1;
	}
	void push_back(DLL_Type data) {		// O(1)
		Vertex* vtx = new Vertex();
		vtx->item = data;
		vtx->prev = tail;
		vtx->next = NULL;
		if (tail != NULL)
			tail->next = vtx;
		tail = vtx;
		if (head == NULL)
			head = vtx;
		num_elements += 1;
	}
	void insert(int i, DLL_Type data) {		// O(N)
		if (i<=0)
			push_front(data);
		else if (i>=num_elements)
			push_back(data);
		else {
			Vertex* vtx = new Vertex();
			vtx->item = data;
			Vertex* bfr = get_element(i-1);
			Vertex* aft = bfr->next;
			bfr->next = vtx;
			vtx->next = aft;
			vtx->prev = bfr;
			aft->prev = vtx;
			num_elements += 1;
		}
	}
	
	// Remove functions
	void pop_front() {	// O(1)
		if (head == NULL)
			return;
		else {
			Vertex* del = head;
			head = head->next;
			if (head != NULL)	
				head->prev = NULL;
			if (head == NULL)
				tail = NULL;
			delete del;
			num_elements -= 1;
		}
	}
	void pop_back() {	// O(1)
		if (tail == NULL)
			return;
		else {
			Vertex* del = tail;
			tail = tail->prev;
			if (tail != NULL)	
				tail->next = NULL;
			if (tail == NULL)
				head = NULL;
			delete del;
			num_elements -= 1;
		}
	}
	void remove(int i) {	// O(N)
		if (i<=0)
			pop_front();
		else if (i>=num_elements-1)
			pop_back();
		else {
			Vertex* bfr = get_element(i-1);
			Vertex* del = bfr->next;
			Vertex* aft = del->next;
			bfr->next = aft;
			aft->prev = bfr;
			delete del;
			num_elements -= 1;
		}
	}
	void clear() {	// O(N)
		while (num_elements>0)
			pop_front();
	}
};

int main() {
	int TC;
	int n, val;
	string c;
	DLL x;
	cin >> TC;
	for(int i=0; i<TC; i++){
		cin >> c >> n;
		cin.get();
		cin.get();
		if (n==0)
			cin.get();
		else		
			for(int j=0; j<n; j++) {
				cin >> val;
				cin.get();
				x.push_back(val);
			}
		int r=0;
		bool error=0;
		for(int j=0; j<c.size(); j++) {
			if (c[j] == 'R') {
				r += 1;
				r = r%2;
			}
			if (c[j] == 'D')
				if (x.size() == 0) {
					cout << "error\n";
					error = 1;
					break;
				}
				else if (r%2==1)
					x.pop_back();
				else
					x.pop_front();
		}
		if (error != 1) {
			n = x.size();
			if (r%2==1) {
				cout << "[";
				if (n>=1) {
					cout << x.back();
					x.pop_back();
					for(int j=1;j<n;j++) {
						cout << "," << x.back();
						x.pop_back();
					}
				}
				cout << "]" << endl;
			} else {
				cout << "[";
				if (n>=1) {
					cout << x.front();
					x.pop_front();
					for(int j=1;j<n;j++) {
						cout << "," << x.front();
						x.pop_front();
					}
				}
				cout << "]" << endl;
			}
		}
	}
	return 0;
}
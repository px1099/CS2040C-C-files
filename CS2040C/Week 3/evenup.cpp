#include <bits/stdc++.h>
using namespace std;

typedef bool SLL_Type;

class SLL {
private:
	// Vertex structure
	struct Vertex {
		SLL_Type item;
		Vertex* next;
	};
	
	// Class elements
	Vertex* head;
	Vertex* tail;
	int num_elements;

public:
	// Constructor
	SLL() {			// O(1)
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
			Vertex* ptr = head;
			for (int k=0; k<i; k++)
				ptr = ptr->next;
			return ptr;
		}
		else
			return NULL;
	}
	
	// Access functions
	SLL_Type* access_front() {	// O(1)
		return &(head->item);
	}
	SLL_Type* access_back() {	// O(1)
		return &(tail->item);
	}
	SLL_Type* access_element(int i) {	// O(N)
		if ((i>=0) && (i<num_elements)) {
			Vertex* ptr = get_element(i);
			return &(ptr->item);
		}
		else
			return NULL;
	}
	
	// Read functions
	SLL_Type front() {	// O(1)
		return head->item;
	}
	SLL_Type back() {	// O(1)
		return tail->item;
	}
	SLL_Type read_element(int i) {	// O(N)
		if ((i>=0) && (i<num_elements)) {
			Vertex* ptr = get_element(i);
			return ptr->item;
		}
	}
	
	// Insert functions
	void push_front(SLL_Type data) {	// O(1)
		Vertex* vtx = new Vertex();
		vtx->item = data;
		vtx->next = head;
		head = vtx;
		if (tail == NULL)
			tail = vtx;
		num_elements += 1;
	}
	void push_back(SLL_Type data) {		// O(1)
		Vertex* vtx = new Vertex();
		vtx->item = data;
		vtx->next = NULL;
		tail->next = vtx;
		tail = vtx;
		if (head == NULL)
			head = vtx;
		num_elements += 1;
	}
	void insert(int i, SLL_Type data) {		// O(N)
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
			delete del;
			if (head == NULL)
				tail = NULL;
			num_elements -= 1;
		}
	}
	void pop_back() {	// O(N)
		if (tail == NULL)
			return;
		else if (head == tail) {
			Vertex* del = tail;
			head = NULL;
			tail = NULL;
			delete del;
			num_elements -= 1;
		} else {
			Vertex* vtx = get_element(num_elements-2);
			Vertex* del = tail;
			tail = vtx;
			tail->next = NULL;
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
			delete del;
			num_elements -= 1;
		}
	}
	void clear() {	// O(N)
		while (num_elements>0)
			pop_front();
	}
};

class STK: private SLL {
public:
	// Element access
	SLL_Type top() {	// O(1)
		return front();
	}
	
	// Capacity functions
	bool stk_empty() {	// O(1)
		return empty();
	}
	int stk_size() {	// O(1)
		return size();
	}
	
	// Modifiers
	void push(SLL_Type data) {	// O(1)
		push_front(data);
	}
	void pop() {	// O(1)
		pop_front();
	}
};

class QUE: private SLL {
public:
	// Element access
	SLL_Type que_front() {	// O(1)
		return front();
	}
	SLL_Type que_back() {	// O(1)
		return back();
	}
	// Capacity functions
	bool que_empty() {	// O(1)
		return empty();
	}
	int que_size() {	// O(1)
		return size();
	}
	
	// Modifiers
	void push(SLL_Type data) {	// O(1)
		push_back(data);
	}
	void pop() {	// O(1)
		pop_front();
	}
};

int main() {
	int n, temp;
	cin >> n;
	STK cards;
	for (int i=0; i<n; i++) {
		cin >> temp;
		temp = temp % 2;
		if (cards.stk_empty() || (cards.top() != temp))
			cards.push(temp);
		else
			cards.pop();
	}
	cout << cards.stk_size() << endl;
	return 0;
}
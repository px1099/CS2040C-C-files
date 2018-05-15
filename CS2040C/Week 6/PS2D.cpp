// PS2D - Pham Quang Minh
#include <bits/stdc++.h>
#define MAXSIZE 100010
using namespace std;

class Sta {
private:
	int arr[MAXSIZE];
	int size;
public:
	Sta() {
		size = 0;
	}
	bool empty() {
		return !size;
	}
	void clear() {
		size = 0;
	}
	void pop() {
		size -= 1;
	}
	int top() {
		return arr[size-1];
	}
	void push(int val) {
		arr[size] = val;
		size += 1;
	}
};

class Que {
private:
	int arr[MAXSIZE];
	int head, tail;
public:
	Que() {
		head = 0;
		tail = -1;
	}
	bool empty() {
		return (head>tail);
	}
	void clear() {
		head = 0;
		tail = -1;
	}
	void pop() {
		head += 1;
	}
	int front() {
		return arr[head];
	}
	void push(int val) {
		tail += 1;
		arr[tail] = val;
	}
};

class Prq {
private:
	int arr[MAXSIZE];
	int size;
public:
	Prq() {
		size = 0;
	}
	bool empty() {
		return !size;
	}
	void clear() {
		size = 0;
	}
	int top() {
		return arr[1];
	}
	void push(int val) {
		size += 1;
		arr[size] = val;
		for (int i=size; (i>1) && (arr[i] > arr[i/2]); i/=2) {
			int temp = arr[i/2];
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
			int left = (i*2 <= size)?(arr[i*2]):(0);
			int right = (i*2+1 <= size)?(arr[i*2+1]):(0);
			if (arr[i] < max(left,right)) {
				int temp = arr[i];
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

int main() {
	int n, command, val, sum;
	bool isSta, isQue, isPrq;
	Sta s;
	Que q;
	Prq p;
	while (cin >> n, n != 0) {
		s.clear();
		q.clear();
		p.clear();
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
	cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked.\n";
	return 0;
}
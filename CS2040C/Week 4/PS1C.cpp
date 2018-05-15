#include <bits/stdc++.h>
#define MAXSIZE 50010
#define HIGH 1000000001
using namespace std;

void addLeft(unsigned long long[],int*,unsigned long long);
void addRight(unsigned long long[],int*,unsigned long long);
void sortLR(unsigned long long[],int*,unsigned long long[],int*);
void popLeft(unsigned long long[],int*);
void popRight(unsigned long long[],int*);
unsigned long long median(unsigned long long[],int,int);

int main() {
	unsigned long long* left = new unsigned long long[MAXSIZE];
	unsigned long long* right = new unsigned long long[MAXSIZE];
	unsigned long long medsum, value;
	int TC, N, L, R; 
	cin >> TC;
	for (int k=0; k<TC; k++) {
		for (int i=0; i<MAXSIZE; i++) {
			left[i] = 0;
			right[i] = HIGH;
		}
		cin >> N;
		cin >> medsum;
		left[0] = medsum;
		right[0] = medsum;
		L = 0;
		R = 0;
		for (int i=1; i<N; i++) {
			cin >> value;
			if (value <= left[0]) {
				addLeft(left, &L, value);
				sortLR(left, &L, right, &R);
			} else {
				addRight(right, &R, value);
				sortLR(left, &L, right, &R);
			}
			medsum += median(left, L, R);
		}
		cout << medsum << endl;
	}
	cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." << endl;
	return 0;
}

void addLeft(unsigned long long left[], int *L, unsigned long long value) {
	int j = *L + 1;
	unsigned long long temp;
	left[j] = value;
	while (left[j] > left[j/2]) {
		temp = left[j/2];
		left[j/2] = left[j];
		left[j] = temp;
		j = j/2;
	}
	*L += 1;
}

void addRight(unsigned long long right[], int *R, unsigned long long value) {
	int j = *R + 1;
	unsigned long long temp;
	right[j] = value;
	while (right[j] < right[j/2]) {
		temp = right[j/2];
		right[j/2] = right[j];
		right[j] = temp;
		j = j/2;
	}
	*R += 1;
}

void sortLR(unsigned long long left[], int *L, unsigned long long right[], int *R) {
	if (*R>*L) {
		addLeft(left, L, left[0]);
		left[0] = right[1];
		right[0] = right[1];
		popRight(right, R);
	} else if ((*L-1)>*R) {
		addRight(right, R, left[0]);
		left[0] = left[1];
		right[0] = left[1];
		popLeft(left, L);
	}
}

void popLeft(unsigned long long left[], int *L) {
	int k = 1;
	unsigned long long temp;
	left[1] = left[*L];
	left[*L] = 0;
	*L -= 1;
	while (left[k] < max(left[2*k],left[2*k+1]))
		if (left[2*k] > left[2*k+1]) {
			temp = left[2*k];
			left[2*k] = left[k];
			left[k] = temp;
			k = 2*k;
		} else {
			temp = left[2*k+1];
			left[2*k+1] = left[k];
			left[k] = temp;
			k = 2*k+1;
		}
}

void popRight(unsigned long long right[], int *R) {
	int k = 1;
	unsigned long long temp;
	right[1] = right[*R];
	right[*R] = HIGH;
	*R -= 1;
	while (right[k] > min(right[2*k],right[2*k+1]))
		if (right[2*k] < right[2*k+1]) {
			temp = right[2*k];
			right[2*k] = right[k];
			right[k] = temp;
			k = 2*k;
		} else {
			temp = right[2*k+1];
			right[2*k+1] = right[k];
			right[k] = temp;
			k = 2*k+1;
		}
}

unsigned long long median(unsigned long long left[], int L, int R) {
	if (L==R)
		return left[0];
	else
		return (left[0] + left[1]) / 2;
}
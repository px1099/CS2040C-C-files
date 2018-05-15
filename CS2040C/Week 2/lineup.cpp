// lineup
#include <bits/stdc++.h>
using namespace std;

void scanArray(string arr[], int size) {
	for (int i=0;i<=size-1;i++)
		cin >> arr[i];
	return;
}

void check(string arr[], int size) {
	int j,decreasing,increasing;
	decreasing = 1;
	increasing = 1;
	for (j=0; j<=size-2; j++) {
		if (arr[j] < arr[j+1]) 
			decreasing = 0;
		if (arr[j] > arr[j+1]) 
			increasing = 0;
	}
	if (decreasing)
		cout << "DECREASING" << endl;
	else if (increasing)
		cout << "INCREASING" << endl;
	else
		cout << "NEITHER" << endl;
}

int main() {
	int N;
	string name[20];
	cin >> N;
	scanArray(name, N);
	check(name,N);
	return 0;
}
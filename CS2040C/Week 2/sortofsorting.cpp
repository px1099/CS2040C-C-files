// sortofsorting
#include <bits/stdc++.h>
using namespace std;

void scanArray(string arr[], int size) {
	for (int i=0;i<=size-1;i++)
		cin >> arr[i];
	return;
}

void bubbleSort(string arr[], int size) {
	int i,j,swapped;
	for (i=size-2; i>=0; i--) {
		swapped = 0;
		for (j=0; j<=i; j++) {
			if (arr[j][0]>arr[j+1][0] || 
				(arr[j][0]==arr[j+1][0] && arr[j][1]>arr[j+1][1])) {
				swap(arr[j],arr[j+1]);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
	return;
}

void printArray(string arr[], int size) {
	for (int i=0;i<=size-1;i++)
		cout << arr[i] << endl;
	return;
}

int main() {
	int n;
	string name[200];
	cin >> n;
	while(n) {
		scanArray(name,n);
		bubbleSort(name, n);
		printArray(name, n);
		cout << endl;
		cin >> n;
	}
	return 0;
}
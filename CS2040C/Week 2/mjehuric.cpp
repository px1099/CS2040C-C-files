// mjehuric
#include <bits/stdc++.h>
#define SIZE 5
using namespace std;

void scanArray(int arr[], int size) {
	for (int i=0;i<=size-1;i++)
		cin >> arr[i];
	return;
}

void printArray(int arr[], int size) {
	for (int i=0;i<=size-2;i++)
		cout << arr[i] << " ";
	cout << arr[size-1] << endl;
	return;
}

void bubbleSort(int arr[], int size) {
	int i,j,swapped;
	for (i=size-2; i>=0; i--) {
		swapped = 0;
		for (j=0; j<=i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j],arr[j+1]);
				printArray(arr,size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
	return;
}

int main() {
	int arr[SIZE];
	scanArray(arr,SIZE);
	bubbleSort(arr,SIZE);
	return 0;
}
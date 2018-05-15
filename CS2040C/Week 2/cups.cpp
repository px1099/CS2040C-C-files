// cups
#include <bits/stdc++.h>
using namespace std;

void scanArray(string color[], int radius[], int N) {
	string s1,s2;
	for (int i=0;i<=N-1;i++) {
		cin >> s1 >> s2;
		if (isdigit(s1[0])) {
			radius[i] = stoi(s1)/2;
			color[i] = s2;
		} else {
			radius[i] = stoi(s2);
			color[i] = s1;
		}
	}
	return;
}

void printArray(string color[], int N) {
	for (int i=0;i<=N-1;i++)
		cout << color[i] << endl;
	return;
}

void bubbleSort(string color[], int radius[], int N) {
	int i,j,swapped;
	for (i=N-2; i>=0; i--) {
		swapped = 0;
		for (j=0; j<=i; j++) {
			if (radius[j] > radius[j+1]) {
				swap(radius[j],radius[j+1]);
				swap(color[j],color[j+1]);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
	return;
}

int main() {
	string color[200];
	int radius[200];
	int N;
	cin >> N;
	scanArray(color, radius, N);
	bubbleSort(color, radius, N);
	printArray(color, N);
	return 0;
}
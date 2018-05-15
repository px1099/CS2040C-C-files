// register
#include <bits/stdc++.h>
using namespace std;
void inputreg(int[]);
void calweight(int[],int[]);
int calvalue(int[],int[]);
int calmax(int[],int[]);

int main() {
	int N, value, max;
	int p[8] = {2,3,5,7,11,13,17,19};
	int v[8],w[8];
	calweight(p,w);
	max = calmax(p,w);
	inputreg(v);
	value = calvalue(v,w);
	N = max - value;
	cout << N << endl;
	return 0;
}

void inputreg(int v[]) {
	for(int i=0;i<8;i++)
		cin >> v[i];
	return;
}

void calweight(int p[],int w[]) {
	w[0] = 1;
	for (int i=1;i<8;i++) 
		w[i] = w[i-1]*p[i-1];
	return;
}

int calvalue(int v[],int w[]) {
	int value = 0;
	for (int i=0;i<8;i++)
		value += (v[i]*w[i]);
	return value;
}

int calmax(int p[],int w[]) {
	int max = 0;
	for (int i=0;i<8;i++)
		max += ((p[i]-1)*w[i]);
	return max;
}
	
	
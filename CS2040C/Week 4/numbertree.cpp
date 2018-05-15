#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1;
	int H;
	cin >> H;
	H = pow(2,H+1);
	string s;
	cin >> s;
	for (int i=0; i<strlen(s.c_str()); i++) {
		n*=2;
		if (s[i] == 'R')
			n+=1;
	}
	cout << H-n << endl;
	return 0;
}
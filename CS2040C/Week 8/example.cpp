#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt","w",stdout);
	/*
	for (int i=0; i<26; i++)
		for (int j=0; j<26; j++) {
			for (int k=0;k<26; k++)
				cout << "1 " << (char) ('A'+i) << (char) ('A'+j) << (char) ('A'+k) << " 1\n";
			cout << "3 A ZZZZ 0" << endl;
		}
	*/
	for (int i=0; i<22; i++)
		cout << "1 " << (char) ('A'+i) << " 1" << endl;
	cout << "1 HA 1" << endl;
	cout << "1 HB 1" << endl;
	cout << "3 A Z 0" << endl;
	cout << "0" << endl;
	return 0;
}
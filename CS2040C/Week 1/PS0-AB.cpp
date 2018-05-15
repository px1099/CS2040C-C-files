#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long A,B;
	cin >> A >> B;
	while (!((A==0)&&(B==0))) {
		cout << A+B << endl;
		cin >> A >> B;
	}
	return 0;
}
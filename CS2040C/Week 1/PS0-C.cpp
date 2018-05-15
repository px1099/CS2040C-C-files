#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long sum,A,B;
	char c;
	cin >> A >> B;
	scanf("%c",&c);
	while (A||B||(c!='\n')) {
		sum = A + B;
		while (c!='\n') {
			cin >> A;
			sum += A;
			scanf("%c",&c);
		}
		cout << sum << endl;
		cin >> A >> B;
	    scanf("%c",&c);
	}
	return 0;
}
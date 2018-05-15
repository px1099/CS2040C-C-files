// rationalsequence2
#include <bits/stdc++.h>
using namespace std;

int main() {
	//	freopen("in.txt", "r", stdin);
	stack<bool> STK;
	int P,K;
	cin >> P;
	for (int i=0; i<P; i++) {
		cin >> K;
		int p,q;
		cin >> p;
		cin.get();
		cin >> q;
		while(p!=q) {
			if (p<q) {
				STK.push(0);
				q-=p;
			} else {
				STK.push(1);
				p-=q;
			}
		}
		int result = 1;
		while(STK.empty() != 1) {
			if (STK.top() == 0)
				result = result*2;
			else
				result = result*2+1;
			STK.pop();
		}
		cout << K << " " << result << endl;
	}
	return 0;
}
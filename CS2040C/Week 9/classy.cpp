// classy
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,string> data;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	//	cout << T << endl;
	for(int i=0; i<T; i++) {
		int n;
		priority_queue<data,vector<data>,greater<data>> PQ;
		cin >> n;
		cin.get();	// Eat '\n' before capturing lines
		//	cout << n << endl;
		for (int j=0; j<n; j++) {
			string line,token,name;
			int classy[10];
			int value=0;
			getline(cin, line);
			istringstream issline(line);
			getline(issline, name, ':');
			issline.get();
			getline(issline, line, ' ');
			istringstream issclassy(line);
			int k=0;
			while(getline(issclassy, token, '-')) {
				if (token == "upper")
					classy[k] = 2;
				else if (token == "middle")
					classy[k] = 1;
				else
					classy[k] = 0;
				k++;
			}
			//	cout << name << endl;
			//	for (int a=0; a<k; a++)
			//  	cout << classy[a] << endl;
			int a;
			for(a=0; a<k; a++)
				value += classy[k-1-a] * pow(3,9-a);
			for(a=k; a<10; a++)
				value += 1 * pow(3,9-a);
			// 	cout << value << endl;
			PQ.push(make_pair((-1)*value, name));
		}
		for (int j=0; j<n; j++) {
			cout << (PQ.top()).second << endl;
			PQ.pop();
		}
		for (int j=0; j<30; j++)
			cout << '=';
		cout << endl;
	}
	return 0;
}
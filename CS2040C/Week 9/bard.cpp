// bard
#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("in.txt", "r", stdin);
	int N;
	int E;
	int song = 0;
	cin >> N >> E;
	bool learned[N+1][E] = {0};
	for (int i=0; i<E; i++) {
		bool bard = 0;
		int num;
		int person;
		vector<int> attend;
		cin >> num;
		for (int j=0; j<num; j++) {
			cin >> person;
			attend.push_back(person);
			if (person == 1)
				bard = 1;
		}
		if (bard == 1) {
			for (int j=0; j<num; j++)
				learned[attend[j]][song] = 1;
			song += 1;
		} else {
			for (int j=0; j<song; j++) {
				bool remember = 0;
				for (int k=0; k<num; k++)
					if (learned[attend[k]][j] == 1)
						remember = 1;
				if (remember == 1)
					for (int k=0; k<num; k++)
						learned[attend[k]][j] = 1;
			}
		}
	}
	for (int i=1; i<=N; i++) {
		bool mastered = 1;
		for (int j=0; j<song; j++)
			if (learned[i][j] == 0)
				mastered = 0;
		if (mastered == 1)
			cout << i << endl;
	}
	return 0;
}
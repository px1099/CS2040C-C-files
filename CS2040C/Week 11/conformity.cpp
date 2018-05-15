// conformity
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull manual_hash(int comb[]) {
	ull result=0;
	for (int i=0; i<5; i++)
		result += comb[i] * pow(500, i);
	return result;
}

int main () {
	//freopen("in.txt","r",stdin);
	
	int n;
	cin >> n;
	unordered_map<ull,int> count;
	int result=0;
	int best=0;
	int courses[5];
	ull comb;
	for (int i=0; i<n; i++) {
		for (int j=0; j<5; j++)
			cin >> courses[j];
		sort(courses, courses+5);
		comb = manual_hash(courses);
		if (count.find(comb) == count.end())
			count[comb] = 1;
		else
			count[comb] += 1;
		if (count[comb] > best)
			best = count[comb];
	}
	for (auto &val: count)
		if (val.second == best)
			result += val.second;
	cout << result << endl;
	return 0;
}
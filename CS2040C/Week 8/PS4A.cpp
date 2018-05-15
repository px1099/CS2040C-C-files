// PS4A
#include <bits/stdc++.h>
using namespace std;

class suggestionsList {
private:
	set<string> maleNamesList;
	set<string> femaleNamesList;
public:
	void AddSuggestion(string &name,int gender) {
		if (gender == 1)
			maleNamesList.insert(name);
		else
			femaleNamesList.insert(name);
	}
	void RemoveSuggestion(string &name) {
		maleNamesList.erase(name);
		femaleNamesList.erase(name);
	}
	int Query(string &Start, string &End, int gender) {
		int count = 0;
		if ((gender==0) || (gender==1))
			count += distance(maleNamesList.lower_bound(Start), maleNamesList.lower_bound(End));
		if ((gender==0) || (gender==2))
			count += distance(femaleNamesList.lower_bound(Start), femaleNamesList.lower_bound(End));
		return count;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen("in.txt", "r", stdin);
	// clock_t start, finish;
	// start = clock();
	suggestionsList NamesList;
	int n, gender;
	string s1, s2;
	while(cin >> n, n!=0) {
		if (n==1) {
			cin >> s1 >> gender;
			NamesList.AddSuggestion(s1,gender);
		} else if (n==2) {
			cin >> s1;
			NamesList.RemoveSuggestion(s1);
		} else {
			cin >> s1 >> s2 >> gender;
			cout << NamesList.Query(s1,s2,gender) << endl;
		}
	}
	// finish = clock();
	// cout << "Running time: " << (double) (finish-start)/CLOCKS_PER_SEC << endl;
	return 0;
}
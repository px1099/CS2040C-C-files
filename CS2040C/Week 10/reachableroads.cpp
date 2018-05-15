// reachableroads
#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<list<int>> &roads, vector<bool> &visited) {
	visited[start] = 1;
	for (auto val: roads[start]) {
		if (visited[val] == 0)
			dfs(val, roads, visited);
	}
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		int m;
		cin >> m;
		vector<list<int>> roads;
		// roads.reserve(m);
		roads.assign(m, list<int> (0,0));
		vector<bool> visited;
		visited.resize(m,0);
		int r;
		cin >> r;
		for (int j=0; j<r; j++) {
			int a, b;
			cin >> a >> b;
			(roads[a]).push_back(b);
			(roads[b]).push_back(a);
		}
		int cc=0;
		for (int j=0; j<m; j++) {
			if (visited[j] == 0) {
				cc++;
				dfs(j, roads, visited);
			}
		}
		cout << cc - 1 << endl;
	}
	return 0;
}
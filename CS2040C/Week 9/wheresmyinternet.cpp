// wheresmyinternet
#include <bits/stdc++.h>
using namespace std;

void DFS(int start, list<int> adj_list[], bool traveled[]) {
	if (traveled[start] == 0) {
		traveled[start] = 1;
		for (auto it=(adj_list[start]).begin(); it!=(adj_list[start]).end(); it++)
			DFS(*it, adj_list, traveled);
	}
	return;
}

int main() {
	//	freopen("in.txt", "r", stdin);
	int N,M;
	cin >> N >> M;
	list<int> adj_list[N+1];
	for (int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		(adj_list[a]).push_back(b);
		(adj_list[b]).push_back(a);
	}
	bool traveled[N+1] = {0};
	DFS(1, adj_list, traveled);
	bool connected = 1;
	for (int i=1; i<=N; i++)
		if (traveled[i] == 0) {
			cout << i << endl;
			connected = 0;
		}
	if (connected == 1)
		cout << "Connected" << endl;
	return 0;
}
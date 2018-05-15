// grid
#include <bits/stdc++.h>
using namespace std;

int grid[500][500];
vector<pair<int,int>> AL[500][500];
int dist[500][500];

void BFS (int i, int j) {
	queue<pair<int,int>> Q;
	Q.push({i,j});
	pair<int,int> u;
	while (Q.empty() == 0) {
		u = Q.front();
		Q.pop();
		for (auto &k: AL[u.first][u.second]) {
			if (dist[k.first][k.second] == -1) {
				dist[k.first][k.second] = dist[u.first][u.second] + 1;
				Q.push(k);
			}
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	int n,m;
	cin >> n >> m;
	cin.get();
	char c;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> c;
			grid[i][j] = (int) (c - '0');
			dist[i][j] = -1;
			if (grid[i][j] != 0) {
				if ((i-grid[i][j]) >= 0)
					AL[i][j].push_back({i-grid[i][j],j});
				if ((i+grid[i][j]) < n)
					AL[i][j].push_back({i+grid[i][j],j});
				if ((j-grid[i][j]) >= 0)
					AL[i][j].push_back({i,j-grid[i][j]});
				if ((j+grid[i][j]) < m)
					AL[i][j].push_back({i,j+grid[i][j]});
			}
		}
		cin.get();
	}
	dist[0][0] = 0;
	
	BFS(0,0);
	cout << dist[n-1][m-1] << endl;
	return 0;
}
// shortestpath1
#include <bits/stdc++.h>
#define INF -1
using namespace std;
typedef pair<int,int> ii;

int main () {
	int n,m,q,s;
	while(cin >> n >> m >> q >> s, n || m || q || s) {
		vector<vector<ii>> AL;	// {dest, weight}
		AL.assign(n, vector<ii>());
		int start, dest, weight;
		for (int i=0; i<m; i++) {
			cin >> start >> dest >> weight;
			AL[start].push_back({dest,weight});
		}
		vector<int> dist;
		dist.assign(n, INF);
		vector<int> parent;
		parent.assign(n, -1);
		priority_queue<ii> PQ;	// {dist, dest)
		
	}
	return 0;
}
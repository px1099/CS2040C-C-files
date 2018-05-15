// PS5B - Labor.cpp
#include <bits/stdc++.h>
using namespace std;

// write your matric number here: A0170723L
// write your name here: Pham Quang Minh
// write list of collaborators here:
// year 2017 Sem2 hash code: WxxVfOfqw6Be7Cyq2acb (do NOT delete this line)

typedef pair<int, int> ii;

// We set V, Q, and AdjList to be global variables so that they are directly accessible in all other methods/functions
// But if you want to refactor this template code to avoid any global variable, you can do so
int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vector<ii>> AdjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge

// distance table of the graph: Dist[i][j] is the shortest distance from i to j
vector<vector<int>> Dist;

// You can add extra function(s) if needed
// --------------------------------------------

void Dijkstra_algorithm(int start) {
	unordered_set<int> connected_vertices = {start};
	unordered_map<int,int> fringe_vertices = {{start,0}};
	priority_queue<ii,vector<ii>,greater<ii>> fringe_distance;
	fringe_distance.push({0,start});
	Dist[start][start] = 0;
	int added_vertex = start;
	while (fringe_vertices.empty() == 0) {
		fringe_vertices.erase(added_vertex);
		fringe_distance.pop();
		for (auto &x: AdjList[added_vertex]) {
			int vertex = x.first;
			if (connected_vertices.find(vertex) == connected_vertices.end()) {	
				int length = Dist[start][added_vertex] + x.second;
				int prev_length = Dist[start][vertex];
				if ((prev_length == -1) || (length < prev_length)) {
					fringe_vertices[vertex] = length;
					fringe_distance.push({length,vertex});
					Dist[start][vertex] = length;
				}
			}
		}
		if (fringe_vertices.empty() == 0) {
			int min_vertex = (fringe_distance.top()).second;
			int min_length = (fringe_distance.top()).first;
			while (
				(fringe_vertices.find(min_vertex) == fringe_vertices.end()) 
				|| (fringe_vertices[min_vertex] != min_length)
			) {
				fringe_distance.pop();
				min_vertex = (fringe_distance.top()).second;
				min_length = (fringe_distance.top()).first;
			}
			added_vertex = min_vertex;
			connected_vertices.insert(added_vertex);
		}
	}
}

// --------------------------------------------

void PreProcess() {
  // Write necessary code to preprocess the graph, if needed
  //
  // write your answer here
  //------------------------------------------------------------------------- 
		
	// clear the distance table and calculate it
	Dist.assign(min(V,10), vector<int> (V,-1));
	for (int i=0; i<min(V,10); i++)
		Dijkstra_algorithm(i);

  //------------------------------------------------------------------------- 
}

int Query(int s, int t, int k) {
  int ans = -1;

  // You have to report the shortest path from Steven and Grace's current position s
  // to reach their chosen hospital t, output -1 if t is not reachable from s
  // with one catch: this path cannot use more than k vertices
  //
  // write your answer here

	ans = Dist[s][t];

  //------------------------------------------------------------------------- 

  return ans;
}

int main() {
  int TC;
  scanf("%d", &TC);

  while (TC--) {
    int j, k, w;
    scanf("%d", &V);
    // clear the graph and read in a new graph as Adjacency List
    AdjList.assign(V, vector<ii>());
    for (int i = 0; i < V; i++) {
      scanf("%d", &k);
      while (k--) {
        scanf("%d %d", &j, &w);
        AdjList[i].emplace_back(j, w); // edge (road) weight (in minutes) is stored here
      }
    }

    PreProcess();

    int source, destination, required_k;
    scanf("%d", &Q);
    while (Q--) {
      scanf("%d %d %d", &source, &destination, &required_k);
      printf("%d\n", Query(source, destination, required_k));
    }

    if (TC)
      printf("\n");
  }
  return 0;
}
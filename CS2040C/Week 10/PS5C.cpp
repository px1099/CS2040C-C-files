// PS5C - Labor.cpp
#include <bits/stdc++.h>
using namespace std;

// write your matric number here: A0170723L
// write your name here: Pham Quang Minh
// write list of collaborators here:
// year 2017 Sem2 hash code: WxxVfOfqw6Be7Cyq2acb (do NOT delete this line)

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

// We set V, Q, and AdjList to be global variables so that they are directly accessible in all other methods/functions
// But if you want to refactor this template code to avoid any global variable, you can do so
int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vector<ii>> AdjList; // the weighted graph (the Singapore map), the length of each edge (road) is stored here too, as the weight of edge
vector<iii> ValidEdge;
vector<int> dist;
vector<int> relaxDist;

// You can add extra function(s) if needed
// --------------------------------------------
	
	
	
// --------------------------------------------

/*
void PreProcess() {
  // Write necessary code to preprocess the graph, if needed
  //
  // write your answer here
  //------------------------------------------------------------------------- 
	
  //------------------------------------------------------------------------- 
}
*/
void relax(int s, int t, int w) {
  if (dist[s] == -1)
	return;
  int weightSum = dist[s] + w;
  if ((relaxDist[t] == -1) || (weightSum < relaxDist[t]))
	relaxDist[t] = weightSum;
}

int Query(int s, int t, int k) {
  // You have to report the shortest path from Steven and Grace's current position s
  // to reach their chosen hospital t, output -1 if t is not reachable from s
  // with one catch: this path cannot use more than k vertices
  //
  // write your answer here
  dist.assign(V,-1);
  dist[s] = 0;
  relaxDist.assign(V,-1);
  relaxDist[s] = 0;
  ValidEdge.clear();
  for(int i=0; i<AdjList[s].size(); i++) {
	int dest = AdjList[s][i].first;
	int weight = AdjList[s][i].second;
	ValidEdge.emplace_back(s,dest,weight);
  }
  for(int i=1; i<k; i++) {
	for (auto a: ValidEdge) {
	  int start = get<0>(a);
	  int dest = get<1>(a);
	  int weight = get<2>(a);
	  relax(start,dest,weight);
	}
	for(int j=0; j<V; j++) {
	  if ((dist[j] != relaxDist[j]) && (dist[j] == -1)) {
		for(int l=0; l<AdjList[j].size(); l++) {
		  int dest = AdjList[j][l].first;
		  int weight = AdjList[j][l].second;
		  ValidEdge.emplace_back(j,dest,weight);
		}
	  }
	  dist[j] = relaxDist[j];
    }
  }
  //------------------------------------------------------------------------- 

  return dist[t];
}

int main() {
  //freopen("in.txt", "r", stdin);
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

    // PreProcess();
	
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
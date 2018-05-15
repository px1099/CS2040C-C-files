// PSM5B
#include <bits/stdc++.h>
using namespace std;

int R;
int C;
int face=0;
int smile=0;
char c;
bool is_face;
bool is_smiling;
vector<vector<char>> grid;

void BFS(int i, int j) {
	if (grid[i][j] == '.')
		return;
	is_face = 1;
	if (grid[i][j] == 'v')
		is_smiling = 1;
	grid[i][j] = '.';
	BFS(i-1,j);
	BFS(i+1,j);
	BFS(i,j+1);
	BFS(i,j-1);
	return;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// ifstream cin ("in.txt");
	cin >> R >> C;
	// scanf("%d %d", &R, &C);
	// cout << R << C;
	// return 0;
	char dummy;
	scanf("%c", &dummy);
	//cout << '.' << 'v' << '#' << endl;
	//cin.get();
	grid.assign(R, vector<char>());
	
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> c;
			(grid[i]).push_back(c);
		}
		scanf("%c",&dummy);
	}
	/*
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++)
			cout << grid[i][j];
		cout << endl;
	}
	*/
	// return 0;
	for (int i=1; i<R-1; i++)
		for (int j=1; j<C-1; j++) {
			is_face = 0;
			is_smiling = 0;
			BFS(i,j);
			face += is_face;
			smile += is_smiling;
		}
	cout << face << endl << smile << endl;
	return 0;
}

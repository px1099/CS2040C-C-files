#include <bits/stdc++.h>
#define MAX 201
using namespace std;
void move(char[][MAX],int,int,int,int,int);

int main() {
	// freopen("in.txt", "r", stdin);
	int R,C,i;	
	char map[MAX][MAX];
	cin >> R >> C;
	for(i=0; i<R; i++) {
		scanf("%s", map[i]);
		// printf("%s\n", map[i]);
	}
	move(map,R,C,0,0,0);
	return 0;
}

void move(char map[][MAX], int R, int C, int r, int c, int d) {
	if (r<0 || r>=R || c<0 || c>=C)
		cout << "Out" << endl;
	switch (map[r][c]) {
		case ' ': cout << "Lost" << endl; break;
		case 'T': cout << d << endl; break;
		case 'N': map[r][c] = ' '; move(map,R,C,r-1,c,d+1); break;
		case 'S': map[r][c] = ' '; move(map,R,C,r+1,c,d+1); break;
		case 'W': map[r][c] = ' '; move(map,R,C,r,c-1,d+1); break;
		case 'E': map[r][c] = ' '; move(map,R,C,r,c+1,d+1); break;					
	}	
	return;
}
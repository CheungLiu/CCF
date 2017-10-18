#include<iostream>
#include<cstring>
using namespace std;
const int N = 50;
const int DIRECTSIZE = 4;
int _next[DIRECTSIZE][2] = { {0,1},{1,0} ,{0,-1}, {-1,0} };//�ң��£�����
char grid[N+1][N+1];
int visited[N + 1][N + 1] = { 0 }, visited2[N + 1][N + 1] = { 0 };
int R, C;
void DFS(int r, int c) {
	int nextr, nextc;
	visited[r][c] = 1;
	for (int i = 0; i < DIRECTSIZE; i++) {
		nextr = r + _next[i][0];
		nextc = c + _next[i][1];
		if (1 > nextr || nextr > R || 1 > nextc || nextc > C || visited[nextr][nextc] || grid[nextr][nextc] == '#')
			continue;
		if ((i == 0 || i == 2) && (grid[r][c] == 'S' || grid[r][c] == 'T' || grid[r][c] == '+' || grid[r][c] == '-'))
			DFS(nextr, nextc);
		else if((i == 1 || i == 3) && (grid[r][c] == 'S' || grid[r][c] == 'T' || grid[r][c] == '+' || grid[r][c] == '|'))
			DFS(nextr, nextc);
		else if (i == 1 && (grid[r][c] == 'S' || grid[r][c] == 'T' || grid[r][c] == '+' || grid[r][c] == '.'))
			DFS(nextr, nextc);
	}
	return;
}
int main() {
	int sr, sc, tr, tc;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'S')
				sr = i, sc = j;
			else if (grid[i][j] == 'T')
				tr = i, tc = j;
		}
	//DFS��Ǵ�'S'����Ե���ĵ�
	memset(visited, 0, sizeof(visited));
	DFS(sr, sc);
	memcpy(visited2, visited, sizeof(visited));
	//ֻ��S�ܵ���T���ܼ����²�����
	if (visited2[tr][tc]) {
		int count = 0;
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
				if (visited2[i][j]) {
					//��Ǵ�i��j��ʼ����¼i��j�ܷ񵽴�T,ÿ�ζ�Ҫ��visited����,�Ա�����ж�
					memset(visited, 0, sizeof(visited));
					DFS(i, j);
					if (!visited[tr][tc])
						count++;
				}
		cout << count << endl;
	}
	else
		cout << "I'm stuck!" << endl;
	return 0;
}
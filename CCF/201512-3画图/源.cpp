#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 100;
char grid[N+1][N+1];
const int DIRECTSIZE = 4;
struct direct {
	int dx, dy;
}Direct[DIRECTSIZE] = { {0,1}, {-1,0}, {0,-1}, {1,0} };//上，左，下，右
void Fill(int x, int y, char c, int m, int n) {
	int nx, ny;
	grid[y][x] = c;
	for (int i = 0; i < DIRECTSIZE; i++) {
		nx = x + Direct[i].dx;
		ny = y + Direct[i].dy;
		if (nx >= 0 && nx < m&&ny >= 0 && ny < n&&grid[ny][nx] != '|'&& grid[ny][nx] != '-'&&grid[ny][nx] != '+'&&grid[ny][nx] != c) 
			Fill(nx, ny, c, m, n);
	}
	return;
}
int main() {
	memset(grid, '.', sizeof(grid));
	int n, m, x1, y1, x2, y2, x, y, q;
	int option, start, end;
	char c;
	//m是宽度，n是高度
	cin >> m >> n >> q;
	for (int i = 1; i <= q; i++) {
		cin >> option;
		if (option == 0) {
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2) {/*
				y1 = n - 1 - y1;
				y2 = n - 1 - y2;*/
				start = min(y1, y2);
				end = max(y1, y2);
				for (int j = start; j <= end; j++) {
					if (grid[j][x1] == '-' || grid[j][x1] == '+')
						grid[j][x1] = '+';
					else
						grid[j][x1] = '|';
				}
			}
			else if(y1==y2){
				//y1 = y2 = n - 1 - y1;
				start = min(x1, x2);
				end = max(x1, x2);
				for (int j = start; j <= end; j++) {
					if (grid[y1][j] == '|' || grid[y1][j] == '+')
						grid[y1][j] = '+';
					else
						grid[y1][j] = '-';
				}
			}
		}
		else if (option == 1) {
			cin >> x >> y >> c;
			y = n - 1 - y;
			Fill(x, y, c, m, n);
		}
	}
	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < m; j++)
			cout << grid[i][j];
		cout << endl;
	}
	return 0;
}
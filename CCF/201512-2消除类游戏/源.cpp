#include<iostream>
using namespace std;
const int N = 30;
int grid[N + 1][N + 1];
inline int myabs(int x) {
	return (x > 0) ? x : -x;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> grid[i][j];
	//消除同行的
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-2;j++)
			if (abs(grid[i][j]) == abs(grid[i][j + 1]) && abs(grid[i][j]) == abs(grid[i][j + 2])) {
				if (grid[i][j] > 0)
					grid[i][j]=-grid[i][j];
				if (grid[i][j + 1] > 0)
					grid[i][j + 1] = -grid[i][j + 1];
				if (grid[i][j + 2] > 0)
					grid[i][j + 2] = -grid[i][j + 2];
			}
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n -2 ; i++)
			if (abs(grid[i][j]) == abs(grid[i+1][j]) && abs(grid[i+1][j]) == abs(grid[i+2][j])) {
				if (grid[i][j] > 0)
					grid[i][j] = -grid[i][j];
				if (grid[i + 1][j] > 0)
					grid[i + 1][j] = -grid[i + 1][j];
				if (grid[i + 2][j] > 0)
					grid[i + 2][j] = -grid[i + 2][j];
			}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] < 0)
				grid[i][j] = 0;
			if (j != 1)
				cout << " ";
			cout << grid[i][j];
		}
		cout << endl;
	}
	return 0;
}
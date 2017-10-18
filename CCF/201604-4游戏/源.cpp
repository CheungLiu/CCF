#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
//0 < n, m ≤ 100，0 ≤ t < 9999，1 ≤ r ≤ n，1 ≤ c ≤ m，0 ≤ a ≤ b ≤ 100。
const int N = 100;
const int DIRECTSIZE = 4;
int visited[N + 1][N + 1][300];
struct direct {
	int row, col, level;
	direct(int a=0, int b=0, int c=0) :row(a), col(b), level(c) {}
}Direct[DIRECTSIZE] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int BFS(int n, int m) {
	direct start, front, v;
	start.row = 1;
	start.col = 1;
	start.level = 0;
	queue<direct> qcon;
	qcon.push(start);
	while (!qcon.empty()) {
		front = qcon.front(); 
		qcon.pop();
		if (front.row == n&&front.col == m)
			return front.level;
		for (int i = 0; i < DIRECTSIZE; i++) {
			//移动一格
			v.row = front.row + Direct[i].row;
			v.col = front.col + Direct[i].col;
			v.level = front.level + 1; 
			if (v.row<1 || v.col<1 || v.row>n || v.col>m || visited[v.row][v.col][v.level])
				continue;
			//因为在v.level的这个时候已经走过了，也变成了危险的时间，标记为不能走
			visited[v.row][v.col][v.level] = 1;
			qcon.push(v);
		}
	}
	return 0;
}
int main() {
	int n, m, t, r, c, a, b;
	memset(visited, 0, sizeof(visited));
	//输入数据
	cin >> n >> m >> t;
	for (int i = 1; i <= t; i++) {
		cin >> r >> c >> a >> b;
		//设置危险时间
		for (int j = a; j <= b; j++)
			visited[r][c][j] = 1;
	}
	int ans = BFS(n, m);
	cout << ans << endl;
	return 0;
}
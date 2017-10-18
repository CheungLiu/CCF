#include<iostream>
using namespace std;
const int N = 4;
const int ROW = 15;
const int COL = 10;
struct node {
	int row, col;
};
struct node coords[N+1];
int block[N + 1][N + 1];
int board[ROW + 2][COL + 1];
int main() {
	int row, col, k = 1;
	int i, j;
	for (int i = 1; i <= ROW; i++)
		for (int j = 1; j <= COL; j++)
			cin >> board[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> block[i][j];
	//col就是表示4X4的最左边
	cin >> col;
	//将最底层设置为1
	for (int i = 1; i <= COL; i++)
		board[ROW + 1][i] = 1;
	//从下到上从左到右提取坐标为1的点
	for(int i=N;i>=1;i--)
		for(int j=1;j<=N;j++)
			if (block[i][j] == 1) {
				coords[k].row = i;
				coords[k].col = j;
				k++;
			}
	row = 1;
	col--;
	//模拟block下降的情况
	bool flag = false;
	while (1) {
		for(int i=1;i<=N;i++)
			if (board[row + coords[i].row][col + coords[i].col] == 1) {
				flag = true;
				break;
			}
		if (flag)
			break;
		row++;
	}
//此时要减去1，因为不减就是重合的
	row--;
	for (int i = 1; i <= N; i++)
		board[row + coords[i].row][col + coords[i].col] = 1;
	for (int i = 1; i <= ROW; i++) {
		for (int j = 1; j <= COL; j++) {
			if (j != 1)
				cout << " ";
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}
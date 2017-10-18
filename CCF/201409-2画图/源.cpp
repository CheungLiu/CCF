#include <iostream>  
#include <cstring>  
using namespace std;
const int N = 100;
bool flag[N + 1][N + 1];
int main()
{
	int n, x1, y1, x2, y2, sum = 0;
	// 变量初始化  
	memset(flag, false, sizeof(flag));
	// 输入数据，计算处理  
	cin >> n;
	for (int i = 1; i <= n; i++) {
		// 输入数据  
		cin >> x1 >> y1 >> x2 >> y2;
		// 累加面积  
		sum += (x2 - x1) * (y2 - y1);
		// 标记和去除重叠部分  
		for (int i = x1; i<x2; i++)
			for (int j = y1; j<y2; j++) {
				if (flag[i][j])
					sum--;
				flag[i][j] = true;
			}
	}
	// 输出结果  
	cout << sum << endl;
	return 0;
}
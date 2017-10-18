//自底向上的采用DP
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1000;
//Min用于备忘机制，v是每一堆的代价，
int Min[N + 1][N + 1], v[N + 1], sum[N + 1];
void DP(int n){
	int i, j, k, l;
	//第一次循环对i=1,2...n-1计算Min[i][i+1],（长度l=2的堆）
	//第二次循环对i=1,2...n-2计算Min[i][i+2],（长度l=3的堆）
	//后面以此类推
	for(l=2;l<=n;l++)
		for (i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;
			Min[i][j] = INF;
			for (k = i; k <= j - 1; k++)
				//sum[j] - sum[i - 1]是计算第i堆到第j堆的代价
				Min[i][j] = min(Min[i][j], Min[i][k] + Min[k + 1][j] + sum[j] - sum[i - 1]);
		}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		//sum用于存放前i堆的代价
		sum[i] = v[i] + sum[i - 1];
		//自己到自己这一堆的代价为零
		Min[i][i] = 0;
	}
	DP(n);
	cout << Min[1][n] << endl;
	return 0;
}
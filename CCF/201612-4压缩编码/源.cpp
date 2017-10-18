//�Ե����ϵĲ���DP
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1000;
//Min���ڱ������ƣ�v��ÿһ�ѵĴ��ۣ�
int Min[N + 1][N + 1], v[N + 1], sum[N + 1];
void DP(int n){
	int i, j, k, l;
	//��һ��ѭ����i=1,2...n-1����Min[i][i+1],������l=2�Ķѣ�
	//�ڶ���ѭ����i=1,2...n-2����Min[i][i+2],������l=3�Ķѣ�
	//�����Դ�����
	for(l=2;l<=n;l++)
		for (i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;
			Min[i][j] = INF;
			for (k = i; k <= j - 1; k++)
				//sum[j] - sum[i - 1]�Ǽ����i�ѵ���j�ѵĴ���
				Min[i][j] = min(Min[i][j], Min[i][k] + Min[k + 1][j] + sum[j] - sum[i - 1]);
		}
	return;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		//sum���ڴ��ǰi�ѵĴ���
		sum[i] = v[i] + sum[i - 1];
		//�Լ����Լ���һ�ѵĴ���Ϊ��
		Min[i][i] = 0;
	}
	DP(n);
	cout << Min[1][n] << endl;
	return 0;
}
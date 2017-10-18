#include<iostream>
using namespace std;
const int N = 500;
int arr[N + 1][N + 1];
bool flag = true;
int main() {
	int n, i, j;
	cin >> n;
	int count = n - 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	//处理n=1的情况
	if (n == 1) {
		cout << arr[n][n] << endl;
		return 0;
	}
	i = j = 1;
	cout << arr[i][j] << " ";
	//count减到0的时候就是上三角形加主对角线输出完毕
	while (count--) {
		if (flag) {//flag为真向左下角
			j++;
			while (i <= n&&j >= 1) {
				cout << arr[i][j] << " ";
				i++, j--;
			}
			i--, j++;
			flag = false;
		}
		else {
			i++;
			while (j <= n&&i >= 1) {
				cout << arr[i][j] << " ";
				i--, j++;
			}
			i++, j--;
			flag = true;
		}
	}
	//n是偶数的话，上面结束时flag为false
	if (n % 2)//奇数时
		//i = 2;在这里不能直接是2
	i = 1;
	else//偶数时
		//j = 2;
	j = 1;
	count = n - 2;
	while (count--) {
		if (flag) {
			//i++;因为每一次转变方向的时候都需要i++;
			i++;
			while (i <= n&&j >= 2) {
				cout << arr[i][j] << " ";
				i++, j--;
			}
			i--, j++;
			flag = false;
		}
		else {
			//j++;因为每一次转变方向的时候都需要j++;
			j++;
			while (j <= n&&i >= 2) {
				cout << arr[i][j] << " ";
				i--, j++;
			}
			i++, j--;
			flag = true;
		}
	}
	cout << arr[n][n] << endl;
	return 0;
}
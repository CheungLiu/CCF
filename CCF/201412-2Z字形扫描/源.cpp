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
	//����n=1�����
	if (n == 1) {
		cout << arr[n][n] << endl;
		return 0;
	}
	i = j = 1;
	cout << arr[i][j] << " ";
	//count����0��ʱ������������μ����Խ���������
	while (count--) {
		if (flag) {//flagΪ�������½�
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
	//n��ż���Ļ����������ʱflagΪfalse
	if (n % 2)//����ʱ
		//i = 2;�����ﲻ��ֱ����2
	i = 1;
	else//ż��ʱ
		//j = 2;
	j = 1;
	count = n - 2;
	while (count--) {
		if (flag) {
			//i++;��Ϊÿһ��ת�䷽���ʱ����Ҫi++;
			i++;
			while (i <= n&&j >= 2) {
				cout << arr[i][j] << " ";
				i++, j--;
			}
			i--, j++;
			flag = false;
		}
		else {
			//j++;��Ϊÿһ��ת�䷽���ʱ����Ҫj++;
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
#include<iostream>
using namespace std;

int ab[1001][1001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> ab[i][j];
	for (int j = m; j >= 1; j--) {
		for (int i = 1; i <= n; i++) {
			if (i != 1)
				cout << " ";
			cout << ab[i][j];
		}
		cout << endl;
	}
	

	return 0;
}
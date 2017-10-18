#include<iostream>
using namespace std;
const int N = 1000;
int main() {
	int n, m, p, q, u, flag=0;
	int queue[N + 1];
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		queue[i] = i;
	for (int i = 1; i <= m; i++ ) {
		cin >> p >> q;
		for (int j = 1; j <= n; j++) {
			if (queue[j] == p) {
				if (q > 0) {
					for (int k = j; k < j + q; k++) {
						queue[k] = queue[k + 1];
						u = k;
					}
					queue[u + 1] = p;
				}
				else {
					for (int k = j; k > j + q; k--) {
						queue[k] = queue[k - 1];
						u = k;
					}
					queue[u - 1] = p;
				}
				break;
			}
		}
	}
	for (int i = 1; i < n; i++)
		cout << queue[i] << " ";
	cout << queue[n];
	return 0;
}
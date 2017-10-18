#include<iostream>
#include<vector>
using namespace std;
vector<int> vec[1002];
int main() {
	int e;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> e;
		vec[e].push_back(1);
	}
	int temp = 0, num;
	for (int j = 0; j<=1000; j++) {
		temp += vec[j].size();
		num = 0;
		for (int q = j + 2; q <= 1000; q++)
			num += vec[q].size();
		if (temp == num&&vec[j + 1].size() != 0) {
			cout << j + 1 << endl;
			break;
		}
		if (j == 1000)
			cout << -1 << endl;
	}
	return 0;
}
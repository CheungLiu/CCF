#include<iostream>
#include<map>
using namespace std;
int main() {
	int n, num, temp = 0, j = 1;
	cin >> n;
	map<int, int> m;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		m[num]++;
	}
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second > temp) {
			temp = it->second;
			j = it->first;
		}
	}
	cout << j << endl;
	return 0;
}

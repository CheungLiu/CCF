#include<iostream>
#include<map>
using namespace std;
int main() {
	map<int, int>mcon;
	int N, sum = 0;
	cin >> N;
	int v;
	for (int i = 1; i <= N; i++) {
		cin >> v;
		if (v < 0)
			mcon[-v]++;
		else
			mcon[v]++;
	}
	int sum = 0;
	for (map<int, int>::iterator it = mcon.begin(); it != mcon.end(); it++)
		if (it->second == 2)
			sum++;
	cout << sum << endl;
	return 0;
}
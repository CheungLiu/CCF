#include<iostream>
#include<map>
using namespace std;
int main() {
	map<int, int> mcon;
	int n, v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		if (i != 1)
			cout << " ";
		mcon[v]++;
		if (mcon.count(v) != 0)
			cout << mcon[v];
		else
			cout << 1;
	}
	cout << endl;
	return 0;
}
#include<iostream>
using namespace std;
int main() {
	int n, last, current, count = 1;
	cin >> n;
	cin >> last;
	for (int i = 2; i <= n; i++) {
		cin >> current;
		if (last != current)
			count++;
		last = current;
	}
	cout << count << endl;
	return 0;
}
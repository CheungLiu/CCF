#include<iostream>
using namespace std;
int main() {
	long long n;
	cin >> n;
	int t;
	t = n % 10;
	n = n / 10;
	while (n) {
		t += n % 10;
		n = n / 10;
	}
	cout << t << endl;
	return 0;
}
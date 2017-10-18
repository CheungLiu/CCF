#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n, a[1001], temp;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int  max = abs(a[2] - a[1]);
	for (int i = 3; i <= n; i++) {
		temp = a[i] - a[i - 1];
		if (abs(temp) > max)
			max = abs(temp);
	}
	cout << max << endl;
	return 0;
}
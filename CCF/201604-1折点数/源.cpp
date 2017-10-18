#include<iostream>
#include<vector>
using namespace std;
int main() {
	int v,n;
	vector<int> vcon;
	int flag = 0;
	cin >> n;
	vcon.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> v;
		vcon.push_back(v);
	}
	for (int i = 2; i < n; i++)
		if ((vcon[i - 1]<vcon[i] && vcon[i]>vcon[i + 1])||(vcon[i - 1]>vcon[i] && vcon[i]<vcon[i + 1]))
			flag++;
	cout << flag << endl;
	return 0;
}
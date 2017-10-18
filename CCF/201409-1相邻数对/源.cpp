#include <iostream>
#include<map> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int n, v, count = 0;
	map<int, int> mcon;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		mcon[v]++;
	}
	map<int, int>::iterator it = mcon.begin();
	int temp = it->first;
	for (it++; it != mcon.end(); it++) {
		if ((it->first - temp) == 1) {
			count++;
		}
		temp = it->first;
	}
	cout << count << endl;
	return 0;
}
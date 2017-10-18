#include<iostream>
#include <string>
#include<cstdio>
using namespace std;
const int N = 13;
int main() {
	string v;
	int sum = 0;
	int sig = 1;
	cin >> v;
	for (int i = 0; i < N - 1; i++) {
		if (v[i] != '-') {
			sum += ((int)v[i] - 48) * sig;
			sig++;
		}
	}
	int code = sum % 11;
	char c = code == 10 ? 'X' : '0' + code;
	if (v[12] == c) {
		cout << "Right";
	}
	else {
		v[12] = c;
		cout << v;
	}
	return 0;
}
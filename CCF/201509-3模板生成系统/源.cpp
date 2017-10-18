#include <iostream>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

int main() {
	vector<string> vcon;
	map<string, string> mcon;
	size_t prev, next;
	int n, m;
	string str, key, value;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		getline(cin, str);
		vcon.push_back(str);
	}

	for (int i = 1; i <= m; i++) {
		cin >> key;
		getline(cin, value);
		mcon[key] = value.substr(2, value.length() - 3);
	}
	for (int i = 0; i<n; i++) {
		while (true) {
			if (((prev = vcon[i].find("{{ ", prev)) == string::npos) || ((next = vcon[i].find(" }}", prev + 1)) == string::npos)) {
				break;
			}
			key = vcon[i].substr(prev + 3, next - prev - 3);
			vcon[i].replace(prev, next - prev + 3, mcon.count(key) ? mcon[key] : "");
			prev += mcon[key].length() ? mcon[key].length() : 0;
		}
		cout << vcon[i] << endl;
	}
	return 0;
}
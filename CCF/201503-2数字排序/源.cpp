#include<iostream>
#include<queue>
#include<map>
using namespace std;
struct node {
	int key, count;
	bool operator<(const node&n)const {
		if (count == n.count)
			return key > n.key;
		else
			return count < n.count;
	}
};
int main() {
	int n, v;
	priority_queue<node> pqcon;
	map<int, int >mcon;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		mcon[v]++;
	}
	node temp;
	for (map<int, int>::iterator it = mcon.begin(); it != mcon.end(); it++) {
		temp.key = it->first;
		temp.count = it->second;
		pqcon.push(temp);
	}
	while (!pqcon.empty()) {
		cout << pqcon.top().key << " " << pqcon.top().count << endl;
		pqcon.pop();
	}
	return 0;
}
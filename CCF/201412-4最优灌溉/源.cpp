#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 1000;
const int M = 10000;
struct edge {
	int src, dest, weight;
	bool operator<(const edge&n)const {
		return weight > n.weight;
	}
};
priority_queue<edge> pqcon;
int get(int parents[],int v) {
	if (parents[v] == v)
		return v;
	return parents[v] = get(parents, parents[v]);
}
int merge(int parents[], int u, int v) {
	int t1 = get(parents, u);
	int t2 = get(parents, v);
	if (t1 != t2) {
		parents[t2] = t1;
		return 1;
	}
	return 0;
}
int main() {
	int n, m, count = 0, sum = 0;
	int parents[N + 1];
	cin >> n >> m;
	//维护的是一棵树
	edge cache;
	for (int i = 1; i <= m; i++) {
		cin >> cache.src >> cache.dest >> cache.weight;
		pqcon.push(cache);
	}
	for (int i = 1; i <= n; i++)
		parents[i] = i;
	for (int i = 1; i <= m; i++) {
		cache=pqcon.top();
		if (merge(parents,cache.src, cache.dest)) {
			sum += cache.weight;
			count++;
		}
		if (count == n - 1)
			break;
		//不论这pqcon.top()是否在同一个树中都要出栈
		pqcon.pop();
	}
	cout << sum << endl;
	return 0;
}
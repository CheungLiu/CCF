#include<iostream>
#include<vector>
#include <cstring> 
using namespace std;
const int N = 10000;
const int M = 10000;
vector<int> vcon[N + M + 1];
int dist[N + M + 1];
void DFS(int start, int next) {
	for (int i = 0; i < vcon[start].size(); i++) {
		if (vcon[start][i] != next) {
			dist[vcon[start][i]] = dist[start] + 1;
			DFS(vcon[start][i], start);
		}
	}
	return;
}
int main() {
	int n, m, v;
	cin >> n >> m;
	for (int i = 2; i <= n; i++) {
		cin >> v;
		vcon[i].push_back(v);
		vcon[v].push_back(i);
	}
	for (int i = n + 1; i <= n + m; i++) {
		cin >> v;
		vcon[i].push_back(v);
		vcon[v].push_back(i);
	}
	memset(dist, 0, sizeof(dist));
	int count = 0;
	DFS(1, 0);
	for (int i = 1; i <= n + m + 1; i++)
		if (dist[i] > dist[count])
			count = i;
	memset(dist, 0, sizeof(dist));
	DFS(count, 0);
	count = 0;
	for (int i = 1; i <= n + m + 1; i++)
		if (dist[i] > dist[count])
			count = i;
	cout << dist[count] << endl;
	return 0;
}
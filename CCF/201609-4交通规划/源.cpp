#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N = 10000;
const int M = 100000;
const int INF = ((unsigned int)(-1) >> 1);
struct edge {
	int e, cost;
	edge(int a=0, int b=0) :e(a), cost(b) {}
	bool operator<(const edge &n)const {
		return cost > n.cost;
	}
};
vector<edge> AdajacencyList[N + 1];
priority_queue<edge> pqcon;
int cost[N + 1], dist[N + 1];
bool visited[N + 1];

void Dijkstra(int start, int n) {
	dist[start] = 0;
	cost[start] = 0;
	pqcon.push(edge(start, 0));
	edge cache;
	while (!pqcon.empty()) {
		cache = pqcon.top();
		pqcon.pop();
		int firsrtE = cache.e;
		if (!visited[firsrtE]) {
			visited[firsrtE] = true;
			int len = AdajacencyList[firsrtE].size();
			for (int i = 0; i < len; i++) {
				int secondE = AdajacencyList[firsrtE][i].e;
				if (visited[secondE])
					continue;
				int tempcost = AdajacencyList[firsrtE][i].cost;
				int nextdist = dist[firsrtE] + tempcost;
				if (dist[secondE] > nextdist) {
					dist[secondE] = nextdist;
					cost[secondE] = tempcost;
					pqcon.push(edge(secondE, dist[secondE]));
				}
				else if(dist[secondE] == nextdist){
					cost[secondE] = min(cost[secondE], tempcost);
				}
			}
		}
	}
	return;
}
int main() {
	int n, m, s, d, w;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s >> d >> w;
		AdajacencyList[s].push_back(edge(d, w));
		AdajacencyList[d].push_back(edge(s, w));
	}
	for (int i = 1; i <= n; i++) {
		cost[i] = INF;
		dist[i] = INF;
		visited[i] = false;
	}
	Dijkstra(1, n);
	int ans = 0;
	for (int i = 2; i <= n; i++)
		ans += cost[i];
	cout << ans << endl;
	return 0;
}
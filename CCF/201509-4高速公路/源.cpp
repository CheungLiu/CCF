#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
const int N = 10000;
const int M = 100000;
int DFN[N + 1];//用来记录时间戳
int LOW[N + 1];//用来记录i结点或者i的子节点能够访问到的最早时间戳
int visited[N + 1];
int isStack[N + 1];
int time = 0;//时间戳
vector<int> vcon[N + 1];
stack<int> scon;
int result = 0;
void Tarjan(int u) {
	//每一个未访问的节点的DFN和LOW都是相同的的
	DFN[u] = LOW[u] = ++time;
	visited[u] = 1;
	scon.push(u);
	isStack[u] = 1;
	int v;
	for (int i = 0; i < vcon[u].size(); i++) {
		v = vcon[u][i];
		//此处要两种情况处理
		//如果v未访问就将v加入栈
		if (!visited[v]) {
			Tarjan(v);
			//在这里进行回溯的时候调整v的父节点u的LOW，如果v能访问到的最早结点时间戳，那么u也能访问到
			LOW[u] = min(LOW[v], LOW[u]);
		}
		//如果v已经访问过在栈中，则调整u的LOW的值
		else if(isStack[v]){
			LOW[u] = min(LOW[u], DFN[v]);
		}
	}
	//当第一次DFN遍历到没有出边的v结点的时候后，就会进入下面这个操作
	int count = 0;
	//此时判断传进来的u结点的LOW和DFN
	if (LOW[u] == DFN[u]) {
		do {
			v = scon.top();
			//标记为不在栈中
			isStack[v] = 0;
			scon.pop();
			count++;
		} while (u != v);//一直弹回到与栈顶相同的结点就组成了一个连通分量
	}
	if (count > 0)
		result += count*(count - 1) / 2;
	return;
}
int main() {
	memset(DFN, 0, sizeof(DFN));
	memset(LOW, 0, sizeof(LOW));
	memset(visited, 0, sizeof(visited));
	memset(isStack,0, sizeof(isStack));
	memset(vcon, 0, sizeof(vcon));
	int n, m;
	int src, dest;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> src >> dest;
		//单向路径
		vcon[src].push_back(dest);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			Tarjan(i);
	cout << result << endl;
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
const int N = 10000;
const int M = 100000;
int DFN[N + 1];//������¼ʱ���
int LOW[N + 1];//������¼i������i���ӽڵ��ܹ����ʵ�������ʱ���
int visited[N + 1];
int isStack[N + 1];
int time = 0;//ʱ���
vector<int> vcon[N + 1];
stack<int> scon;
int result = 0;
void Tarjan(int u) {
	//ÿһ��δ���ʵĽڵ��DFN��LOW������ͬ�ĵ�
	DFN[u] = LOW[u] = ++time;
	visited[u] = 1;
	scon.push(u);
	isStack[u] = 1;
	int v;
	for (int i = 0; i < vcon[u].size(); i++) {
		v = vcon[u][i];
		//�˴�Ҫ�����������
		//���vδ���ʾͽ�v����ջ
		if (!visited[v]) {
			Tarjan(v);
			//��������л��ݵ�ʱ�����v�ĸ��ڵ�u��LOW�����v�ܷ��ʵ���������ʱ�������ôuҲ�ܷ��ʵ�
			LOW[u] = min(LOW[v], LOW[u]);
		}
		//���v�Ѿ����ʹ���ջ�У������u��LOW��ֵ
		else if(isStack[v]){
			LOW[u] = min(LOW[u], DFN[v]);
		}
	}
	//����һ��DFN������û�г��ߵ�v����ʱ��󣬾ͻ���������������
	int count = 0;
	//��ʱ�жϴ�������u����LOW��DFN
	if (LOW[u] == DFN[u]) {
		do {
			v = scon.top();
			//���Ϊ����ջ��
			isStack[v] = 0;
			scon.pop();
			count++;
		} while (u != v);//һֱ���ص���ջ����ͬ�Ľ��������һ����ͨ����
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
		//����·��
		vcon[src].push_back(dest);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			Tarjan(i);
	cout << result << endl;
	return 0;
}
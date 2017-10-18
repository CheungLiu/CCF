#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 100;
const int M = 100;
struct node {
	long long x, y;
	int step;
	node(int a=0, int b=0, int c=0) :x(a), y(b), step(c) {}
}coords[N + M + 1];
bool visited[N + M + 1];
int BFS(int n, int begin, int end, long long r) {
	memset(visited, false, sizeof(visited));
	node start, front, v;
	start.x = coords[begin].x;
	start.y = coords[begin].y;
	start.step = 0;
	queue<node> qcon;
	qcon.push(start);
	visited[begin] = true;
	while (!qcon.empty()) {
		front = qcon.front();
		qcon.pop();
		//�������end���ͽ���
		if (front.x == coords[end].x&&front.y == coords[end].y)
			return front.step - 1;
		//���ӿɴ��·����
		for (int i = 1; i <= n; i++) {
			//���ʹ�������
			if (visited[i])
				continue;
			//�ж����·�����������Ƿ���r�뾶��Χ��
			if ((front.x - coords[i].x)*(front.x - coords[i].x) + (front.y - coords[i].y)*(front.y - coords[i].y)>r*r)
				continue;
			else {
				//���õ�i��·�������ʹ�
				visited[i] = true;
				v.x = coords[i].x;
				v.y = coords[i].y;
				v.step = front.step + 1;
				qcon.push(v);
			}
		}
	}
	return 0;
}
int main() {
	int n, m, k;
	long long r;
	cin >> n >> m >> k >> r;
	for (int i = 1; i <= n + m; i++)
		cin >> coords[i].x >> coords[i].y;
	int ans = BFS(n + m, 1, 2, r);
	cout << ans << endl;
	return 0;
}
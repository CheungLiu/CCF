#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>
using namespace std;
struct recttangle{
	int x1, y1, x2, y2, num;

	recttangle(int a=0, int b=0, int c=0, int d=0, int n=0) :x1(a), y1(b), x2(c), y2(d), num(n) {}
	/*recttangle(int a=0, int b=0, int c=0, int d=0, int n=0) {
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
		num = n;
	}*/
};
struct coordinate1{
	int x, y;
};
coordinate1 click[11];
int main() {
	int N, M, x, y;
	bool flag = false;
	vector<recttangle> vcon;
	vcon.push_back(recttangle(0, 0, 0, 0, 0));
	cin >> N >> M;
	int x1, y1, x2, y2;
	for (int i = 1; i <= N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		vcon.push_back(recttangle(x1, y1, x2, y2, i));
	}
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		click[i].x = x;
		click[i].y = y;
	}
	for (int i = 1; i <= M; i++) {
		for (vector<recttangle>::iterator it = vcon.end() - 1; it != vcon.begin(); it--) {
			if (click[i].x >= it->x1&&click[i].x <= it->x2&&click[i].y >= it->y1&&click[i].y <= it->y2) {
				cout << it->num << endl;
				if (flag) {//最开始不会进去，因为在最顶层不存在变换窗口标号
					recttangle temp;
					temp = *it;
					for (it; it != vcon.end()-1; it++)
						*it = *(it+1);
					*it = temp;
					flag = false;
				}
				break;
			}
			if (it == vcon.begin()+1)
				cout << "IGNORED" << endl;
			if (!flag)
				flag = true;
		}	
	}

	return 0;
}
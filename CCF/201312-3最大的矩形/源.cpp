#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
const int N = 1000;
int h[N + 1];
int main() {
	int n, ans = 0, area, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	h[n] = 0;
	//计算最大矩形面积
	stack<int>s;
	for (int i = 0; i <= n; i++) {
		//堆栈为空或者是递增的矩形加入
		if (s.empty() || h[s.top()] < h[i])
			s.push(i);
		else {
			temp = s.top();
			//把比当前高的堆栈弹出
			s.pop();
			// i - s.top() - 1是为了计算出有多少个连续递增的矩形
			area = h[temp] * (s.empty() ? i : i - s.top() - 1);
			  //area = h[temp] * (i - sS.top() - 1);
			ans = max(ans, area);
			i--;
		}
	}
	cout << ans << endl;
	return 0;
}


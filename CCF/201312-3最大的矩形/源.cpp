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
	//�������������
	stack<int>s;
	for (int i = 0; i <= n; i++) {
		//��ջΪ�ջ����ǵ����ľ��μ���
		if (s.empty() || h[s.top()] < h[i])
			s.push(i);
		else {
			temp = s.top();
			//�ѱȵ�ǰ�ߵĶ�ջ����
			s.pop();
			// i - s.top() - 1��Ϊ�˼�����ж��ٸ����������ľ���
			area = h[temp] * (s.empty() ? i : i - s.top() - 1);
			  //area = h[temp] * (i - sS.top() - 1);
			ans = max(ans, area);
			i--;
		}
	}
	cout << ans << endl;
	return 0;
}


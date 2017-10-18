#include<iostream>
using namespace std;
inline int leapyear(int i) {
	  return ((!(i % 4) && i % 100) || (!(i % 400))) ? 1 : 0;
}
int main() {
	int a, b, c, y1, y2, week, day;
	int months[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31},
					{ 0,31,29,31,30,31,30,31,31,30,31,30,31 } };
	cin >> a >> b >> c >> y1 >> y2;
	int days = 0;
	//����1850��y1��ǰһ�������
	for (int i = 1850; i < y1; i++)
		days += 365 + leapyear(i);//���������һ��
	for (int i = y1; i <= y2; i++) {
		int y = leapyear(i);
		//�����i��a-1�µ�ǰһ�������
		int days2 = days;
		//����a-1�µ����һ�������ڼ�
		for (int j = 1; j < a; j++)
			days2 += months[y][j];
		week = 1 + days2 % 7;
		day = (b - 1) * 7 + ((week >= c) ? (7 - week + c) : (c - week));
		if (day > months[y][a])
			cout << "none" << endl;
		else {
			cout << i << "/";
			if (a < 10)
				cout << "0";
			cout << a << "/";
			if (day < 10)
				cout << "0";
			cout << day << endl;
		}
		days += 365 + leapyear(i);//���Ͻ��꣬Ϊ��һ����׼��
	}
	return 0;
}
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
	//计算1850到y1的前一年的天数
	for (int i = 1850; i < y1; i++)
		days += 365 + leapyear(i);//是闰年会多加一天
	for (int i = y1; i <= y2; i++) {
		int y = leapyear(i);
		//计算第i年a-1月的前一天的天数
		int days2 = days;
		//计算a-1月的最后一天是星期几
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
		days += 365 + leapyear(i);//加上今年，为下一年做准备
	}
	return 0;
}
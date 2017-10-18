#include<iostream>
using namespace std;
int year[] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int y, d, days = 0, month, day;
	cin >> y;
	cin >> d;
	if (!(y % 400) || (!(y % 4) && (y % 100)))
		year[1] = 29;
	else
		year[1] = 28;
	for (int i = 0; i < 12; i++) {
		days += year[i];
		if (days >= d) {
			month = i + 1;
			day = year[i]  - days + d;
			break;
		}
	}
	cout << month << endl << day << endl;
	return 0;
}
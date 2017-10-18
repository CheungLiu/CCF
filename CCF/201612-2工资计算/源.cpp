#include<iostream>
using namespace std;
int main() {
	float x, salary;
	cin >> x;
	if (x <= 3500)				salary = x;
	if (x <= 4955 && x>3500)    salary = (x - 3500 * 0.03) / 0.97;
	if (x <= 7655 && x>4955)    salary = (x - (3500 + 1500) * 0.1 + 45) / 0.9;
	if (x <= 11255 && x>7655)   salary = (x - (3500 + 4500)*0.2 + 345) / 0.8;
	if (x <= 30755 && x>11255) 	salary = (x - (3500 + 9000)*0.25 + 1245) / 0.75;
	if (x <= 44755 && x>30755)  salary = (x - (3500 + 35000)*0.3 + 7745) / 0.7;
	if (x <= 61005 && x>44755) 	salary = (x - (3500 + 55000)*0.35 + 13745) / 0.65;
	if (x>61005)			    salary = (x - (3500 + 80000)*0.45 + 22495) / 0.55;
	cout << salary << endl;
	return 0;
}
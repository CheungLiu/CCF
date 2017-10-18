#include<string>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<queue>
using namespace std;
int cancel[5001];
struct trading {
	int orderNO;
	float price;
	char c;
	long long quantity;
	bool operator<(const trading &n)const {
		if (c == 'b')
			return price<n.price;
		else
			return price>n.price;
	}
};
int main() {
	priority_queue<trading> buy, sell;
	memset(cancel, false, sizeof(cancel));
	trading tcache;
	int NO = 0, cancelNO = 0;
	string str;
	while (cin >> str) {
		if (str[0] == 'b' || str[0] == 's') {
			cin >> tcache.price >> tcache.quantity;
			tcache.c = str[0];
			tcache.orderNO = ++NO;
			if (str[0] == 'b')
				buy.push(tcache);
			else
				sell.push(tcache);
		}
		else if (str[0] == 'c') {
			NO++;
			cin >> cancelNO;
			cancel[cancelNO] = true;
		}
		else
			break;
	}
	trading b, s;
	tcache.price = 0;
	tcache.quantity = 0;
	while (true) {
		while (!buy.empty()) {
			b = buy.top();
			if (cancel[b.orderNO])
				buy.pop();
			else
				break;
		}
		while (!sell.empty()) {
			s = sell.top();
			if (cancel[s.orderNO])
				sell.pop();
			else
				break;
		}
		if (buy.empty() || sell.empty())
			break;
		if (b.price >= s.price) {
			tcache.price = b.price;
			tcache.quantity += min(b.quantity, s.quantity);
			if (b.quantity>s.quantity) {
				b.quantity -= s.quantity;
				buy.push(b);
			}
			else if (b.quantity<s.quantity) {
				s.quantity -= b.quantity;
				sell.push(s);
			}
			buy.pop();
			sell.pop();
		}
		else
			break;
	}
	printf("%.2f", tcache.price);
	cout << " " << tcache.quantity << endl;
	return 0;
}
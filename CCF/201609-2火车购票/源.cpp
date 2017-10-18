#include <iostream>  
#include <map>  
using namespace std;
const int N = 20;
const int NUM = 5;
int main()
{
	map<int, int> mcon;
	for (int i = 1; i <= N; i++)
		mcon[i] = NUM;
	int n, v, start, end;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		//循环一边找到能满足v的第几排座位
		for (map<int, int>::iterator it = mcon.begin(); it != mcon.end(); it++) {
			if (it->second >= v) {
				start = it->first*NUM + 1 - it->second;
				//不能像下面这样，因为it->second是会变化的
				//start = (it->first - 1)*NUM + 1;
				end = start - 1 + v;
				for (int j = start; j < end; j++)
					cout << j << " ";
				cout << end << endl;
				it->second -= v;
				v = 0;
				break;
			}
		}
		//当所有座位都不能满足v的时候，就不能安排到连续的位置
		while (v > 0) {
			for (map<int, int>::iterator it = mcon.begin(); it != mcon.end(); it++) {
				//这里的if语句虽然和上面的一样的，但是在最后一次的安排中it->second是会满足v的，因为每一次v是在减少，所以不能缺少
				if (v - it->second <= 0) {
					start = it->first*NUM + 1 - it->second;
					end = start + v - 1;
					for (int j = start; j < end; j++)
						cout << j << " ";
					cout << end << endl;
					it->second -= v;
					v = 0;
					break;
				}
				if (it->second > 0) {
					start = it->first*NUM + 1 - it->second;
					end = start + it->second - 1;
					for (int j = start; j <= end; j++)
						cout << j << " ";
					v -= it->second;
					//进入这个if语句的都是能把此it->second的完全占完
					it->second = 0;
					continue;
				}
			}
		}
	}
	return 0;
}
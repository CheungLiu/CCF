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
		//ѭ��һ���ҵ�������v�ĵڼ�����λ
		for (map<int, int>::iterator it = mcon.begin(); it != mcon.end(); it++) {
			if (it->second >= v) {
				start = it->first*NUM + 1 - it->second;
				//������������������Ϊit->second�ǻ�仯��
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
		//��������λ����������v��ʱ�򣬾Ͳ��ܰ��ŵ�������λ��
		while (v > 0) {
			for (map<int, int>::iterator it = mcon.begin(); it != mcon.end(); it++) {
				//�����if�����Ȼ�������һ���ģ����������һ�εİ�����it->second�ǻ�����v�ģ���Ϊÿһ��v���ڼ��٣����Բ���ȱ��
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
					//�������if���Ķ����ܰѴ�it->second����ȫռ��
					it->second = 0;
					continue;
				}
			}
		}
	}
	return 0;
}
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1000;
char v[2 * N], t[N];
char curpath[N];
void mygetline(char *p) {
	char c;
	while ((c = getchar()) != '\n'&&c != 'EOF') {
		*p++ = c;
	}
	*p = '\0';
	return;
}
void split(vector<string> &vs, char *p) {
	char *s;
	//������///���ᱻpush��vs
	s = strtok(p, "/");
	while (s) {
		//�˴���C++�ַ��������ֵ����ַ������׵�ַ����Ϊvs��ÿ��vs[i]����һ���ַ����飬����ֱ�Ӹ�ֵ
		vs.push_back(s);
		s = strtok(NULL, "/");
	}
	return;
}
//���ǵ�Ŀ�ľ���Ҫ��..��.���""�ַ���
void process(vector<string> &vs) {
	int delcount = 0;
	for (int i = 0; i <vs.size(); i++) {
		if (vs[i] == "..") {
			delcount++;
			vs[i] = "";
			for (int j = i - 1; j >= 0; j--) {
				if (vs[j] != "") {
					delcount++;
					vs[j] = "";
					break;
				}
			}
		}
		else if (vs[i] == ".") {
			vs[i] = "";
			delcount++;
		}
	}
	//""�ַ�������vs�ĳ���ʱ��˵�����滯���Ǹ�Ŀ¼
	if (vs.size() - delcount <= 0) {
		cout << "/" << endl;
	}
	else {
		for (int i = 0; i < vs.size(); i++) {
			//ֻҪ�Ƿ��ַ��������
			if (vs[i] != "") {
				cout << "/" << vs[i];
			}
		}
		cout << endl;
	}
	return;
}
int main() {
	int p;
	cin >> p;
	//��ȡ��ǰ·��
	cin >> curpath;
	getchar();
	for (int i = 1; i <= p; i++) {
		vector<string> vs;
		//��ȡ��Ҫ���滯��·��
		mygetline(t);
		//����ǵ�ǰ�ļ�
		if (t[0] != '/') {
			//���ڶ����ַ�����ͨ'\0'���Ƶ���һ���ַ���
			strcpy(v, curpath);
			//cat�������ǽ��ڶ����ַ����ӵ���һ���ַ������淵���ַ�����һ���׵�ַ
			strcat(v, "/");
			strcat(v, t);
			split(vs, v);
		}
		else
			//strcpy(v, t);
			split(vs, t);
		//�з�·��
		//split(vs, v);
		process(vs);
	}
	return 0;
}
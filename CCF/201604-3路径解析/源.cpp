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
	//连续的///不会被push进vs
	s = strtok(p, "/");
	while (s) {
		//此处是C++字符串的名字等于字符串的首地址，因为vs是每个vs[i]都是一个字符数组，可以直接赋值
		vs.push_back(s);
		s = strtok(NULL, "/");
	}
	return;
}
//我们的目的就是要将..和.变成""字符串
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
	//""字符串大于vs的长度时就说明正规化就是根目录
	if (vs.size() - delcount <= 0) {
		cout << "/" << endl;
	}
	else {
		for (int i = 0; i < vs.size(); i++) {
			//只要是非字符串就输出
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
	//获取当前路径
	cin >> curpath;
	getchar();
	for (int i = 1; i <= p; i++) {
		vector<string> vs;
		//获取需要正规化的路径
		mygetline(t);
		//处理非当前文件
		if (t[0] != '/') {
			//将第二个字符串连通'\0'复制到第一个字符创
			strcpy(v, curpath);
			//cat的作用是将第二个字符串加到第一个字符串后面返回字符数组一的首地址
			strcat(v, "/");
			strcat(v, t);
			split(vs, v);
		}
		else
			//strcpy(v, t);
			split(vs, t);
		//切分路径
		//split(vs, v);
		process(vs);
	}
	return 0;
}
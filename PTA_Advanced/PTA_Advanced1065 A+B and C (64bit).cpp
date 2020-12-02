//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//
//typedef long long LL;
//int main()
//{
//	LL A, B, C;
//	int N, caseNum = 1;
//	int ret = scanf("%d", &N);	
//	bool flag;
//	while (N--) {
//		ret = scanf("%lld%lld%lld", &A, &B, &C);
//		LL res = A + B;
//		if (A > 0 && B > 0 && res < 0) flag = true;//正溢出
//		else if (A < 0 && B < 0 && res >= 0)flag = false;//负溢出
//		else if (res > C) flag = true;
//		else flag = false;
//		if (!flag) {
//			printf("Case #%d: false\n", caseNum++);
//		}
//		else {
//			printf("Case #%d: true\n", caseNum++);
//		}
//	}
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Bign {
	int d[1000] = { 0 };//若不初始化，无法通过第1个测试点
	int len;
	int flag;//1表示正数，-1表示负数
	Bign() {
		len = 0;
		flag = 1;
	}
};

Bign change(string str) {//将字符串转换成大数
	Bign res;
	for (int i = str.size() - 1; i >= 0; --i) {
		res.d[res.len++] = str[i] - '0';
	}
	return res;
}

Bign Add(Bign a, Bign b) {//加法
	Bign res;
	int carry = 0;
	for (int i = 0, j = 0; i < a.len || j < b.len; ++i, ++j) {
		int tmp = a.d[i] + b.d[j] + carry;
		res.d[res.len++] = tmp % 10;
		carry = tmp / 10;
	}
	if (carry) res.d[res.len++] = carry;
	return res;
}

Bign Sub(Bign a, Bign b) {//减法
	Bign res;
	for (int i = 0, j = 0; i < a.len || j < b.len; ++i, ++j) {//保证a>b
		if (a.d[i] < b.d[j]) {
			--a.d[i + 1];
			a.d[i] += 10;
		}
		res.d[res.len++] = a.d[i] - b.d[j];
	}
	for (int i = res.len - 1; i > 0 && res.d[i] == 0; --i, --res.len);//去除高位0，当至少保留一位数
	return res;
}

bool com(Bign a, Bign b) {//比较大数大小
	if (a.len != b.len) return a.len > b.len;
	else {
		for (int i = a.len - 1; i >= 0; --i) {
			if (a.d[i] != b.d[i])
				return a.d[i] > b.d[i];
		}
	}
	return false;
}

int main()
{
	string str[3];//存储A,B,C
	int N, flag;
	Bign num[3];//存储A,B,C对应的大数
	int cnt = 1;
	cin >> N;
	while (N--) {		
		for (int i = 0; i < 3; ++i) {
			cin >> str[i];
			flag = 1;
			if (str[i][0] == '-') {
				str[i] = str[i].substr(1);
				flag = -1;
			}
			num[i] = change(str[i]);
			num[i].flag = flag;
		}
		if (!com(num[0], num[1])) {//保证前者大于后者
			swap(num[0], num[1]);
		}
		if (num[0].flag * num[1].flag > 0) {//A,B符号相同
			auto sum = Add(num[0], num[1]);
			printf("Case #%d: ", cnt++);
			if (num[0].flag > 0 && num[2].flag > 0) {//C正，比较A，B之和与C的大小
				if (com(sum, num[2]))
				printf("true\n");
				else printf("false\n");
			}
			else if (num[0].flag > 0 && num[2].flag < 0) printf("true\n");//C负，显然A+B大于C
			else if (num[0].flag < 0 && num[2].flag < 0) {//C负，A+B负
			if (com(sum, num[2]))
				printf("false\n");
				else printf("true\n");
			}
			else printf("false\n");//C正，A+B负
		}
		else if (num[0].flag > 0 && num[1].flag < 0) {//A正B负
			printf("Case #%d: ", cnt++);
			auto sum = Sub(num[0], num[1]);
			if (num[2].flag > 0) {//C正
				if (com(sum, num[2])) printf("true\n");
				else printf("false\n");
			}
			else printf("true\n");//C负
		}
		else {//A负B正
			printf("Case #%d: ", cnt++);
			auto sum = Sub(num[0], num[1]);
			if (num[2].flag > 0) printf("false\n");//C正
			else {
				if (com(sum, num[2])) printf("false\n");
				else printf("true\n");
			}
		}
	}
	return 0;
}
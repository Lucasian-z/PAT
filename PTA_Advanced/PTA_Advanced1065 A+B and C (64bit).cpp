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
//		if (A > 0 && B > 0 && res < 0) flag = true;//�����
//		else if (A < 0 && B < 0 && res >= 0)flag = false;//�����
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
	int d[1000] = { 0 };//������ʼ�����޷�ͨ����1�����Ե�
	int len;
	int flag;//1��ʾ������-1��ʾ����
	Bign() {
		len = 0;
		flag = 1;
	}
};

Bign change(string str) {//���ַ���ת���ɴ���
	Bign res;
	for (int i = str.size() - 1; i >= 0; --i) {
		res.d[res.len++] = str[i] - '0';
	}
	return res;
}

Bign Add(Bign a, Bign b) {//�ӷ�
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

Bign Sub(Bign a, Bign b) {//����
	Bign res;
	for (int i = 0, j = 0; i < a.len || j < b.len; ++i, ++j) {//��֤a>b
		if (a.d[i] < b.d[j]) {
			--a.d[i + 1];
			a.d[i] += 10;
		}
		res.d[res.len++] = a.d[i] - b.d[j];
	}
	for (int i = res.len - 1; i > 0 && res.d[i] == 0; --i, --res.len);//ȥ����λ0�������ٱ���һλ��
	return res;
}

bool com(Bign a, Bign b) {//�Ƚϴ�����С
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
	string str[3];//�洢A,B,C
	int N, flag;
	Bign num[3];//�洢A,B,C��Ӧ�Ĵ���
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
		if (!com(num[0], num[1])) {//��֤ǰ�ߴ��ں���
			swap(num[0], num[1]);
		}
		if (num[0].flag * num[1].flag > 0) {//A,B������ͬ
			auto sum = Add(num[0], num[1]);
			printf("Case #%d: ", cnt++);
			if (num[0].flag > 0 && num[2].flag > 0) {//C�����Ƚ�A��B֮����C�Ĵ�С
				if (com(sum, num[2]))
				printf("true\n");
				else printf("false\n");
			}
			else if (num[0].flag > 0 && num[2].flag < 0) printf("true\n");//C������ȻA+B����C
			else if (num[0].flag < 0 && num[2].flag < 0) {//C����A+B��
			if (com(sum, num[2]))
				printf("false\n");
				else printf("true\n");
			}
			else printf("false\n");//C����A+B��
		}
		else if (num[0].flag > 0 && num[1].flag < 0) {//A��B��
			printf("Case #%d: ", cnt++);
			auto sum = Sub(num[0], num[1]);
			if (num[2].flag > 0) {//C��
				if (com(sum, num[2])) printf("true\n");
				else printf("false\n");
			}
			else printf("true\n");//C��
		}
		else {//A��B��
			printf("Case #%d: ", cnt++);
			auto sum = Sub(num[0], num[1]);
			if (num[2].flag > 0) printf("false\n");//C��
			else {
				if (com(sum, num[2])) printf("false\n");
				else printf("true\n");
			}
		}
	}
	return 0;
}
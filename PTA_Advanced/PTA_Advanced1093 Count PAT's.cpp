#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

const int maxn = 100010;
char str[maxn];
int cntP[maxn] = { 0 };
int cntT[maxn] = { 0 };
int main()
{
	int ret = scanf("%s", str);
	int len = strlen(str);
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		if (str[i] == 'P') cntP[i] = i > 0 ? cntP[i - 1] + 1 : 1;//如果是P，则继承上一个位置的值并加1
		else if (i > 0) cntP[i] = cntP[i - 1];//如果不是P，则继承上一个位置的值
	}
	for (int i = len - 1; i >= 0; --i) {
		if (str[i] == 'T') cntT[i] = i < len - 1 ? cntT[i + 1] + 1 : 1;//同上
		else if (i < len - 1) {
			cntT[i] = cntT[i + 1];
			if (str[i] == 'A')
				ans = (ans + cntP[i] * cntT[i]) % 1000000007;//不能写成ans += (cntP[i] * cntT[i]) % 1000000007
		}
	}
	printf("%d", ans);
	return 0;
}

//算法笔记
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

const int maxn = 100010;
char str[maxn];
int cntP[maxn] = { 0 };
int cntT[maxn] = { 0 };
int main()
{
	int ret = scanf("%s", str);
	int len = strlen(str);
	int ans = 0, rightTNum = 0;
	for (int i = 0; i < len; ++i) {
		if (i > 0) cntP[i] = cntP[i - 1];
		if (str[i] == 'P') ++cntP[i];
	}
	for (int i = len - 1; i >= 0; --i) {
		if (str[i] == 'T') ++rightTNum;
		if (str[i] == 'A') {
			ans = (ans + cntP[i] * rightTNum) % 1000000007;
		}
	}
	printf("%d", ans);
	return 0;
}
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
		if (str[i] == 'P') cntP[i] = i > 0 ? cntP[i - 1] + 1 : 1;//�����P����̳���һ��λ�õ�ֵ����1
		else if (i > 0) cntP[i] = cntP[i - 1];//�������P����̳���һ��λ�õ�ֵ
	}
	for (int i = len - 1; i >= 0; --i) {
		if (str[i] == 'T') cntT[i] = i < len - 1 ? cntT[i + 1] + 1 : 1;//ͬ��
		else if (i < len - 1) {
			cntT[i] = cntT[i + 1];
			if (str[i] == 'A')
				ans = (ans + cntP[i] * cntT[i]) % 1000000007;//����д��ans += (cntP[i] * cntT[i]) % 1000000007
		}
	}
	printf("%d", ans);
	return 0;
}

//�㷨�ʼ�
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
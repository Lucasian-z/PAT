#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int MAXN = 200005;
long long arr1[MAXN], arr2[MAXN];//分别存储两个数列
int main()
{
	long long num;
	int N1, N2, i, j;
	int ret = scanf("%d", &N1);
	for (i = 0; i < N1; ++i) {
		ret = scanf("%lld", &arr1[i]);
	}
	ret = scanf("%d", &N2);
	for (i = 0; i < N2; ++i) {
		ret = scanf("%lld", &arr2[i]);
	}
	i = j = 0;
	int mid = (N1 + N2) >> 1;//中间位置
	while (i < N1 && j < N2) {//如果N1+N2为偶数，则中位数为左半部分的最后一个数
		if (i + j == mid && (N1 + N2) % 2 == 1 || i + j == mid - 1 && (N1 + N2) % 2 == 0) {
			printf("%lld\n", arr1[i] < arr2[j] ? arr1[i] : arr2[j]);
			return 0;
		}
		if (arr1[i] < arr2[j]) ++i;
		else ++j;
	}
	if (i < N1 && mid >= j) {
		printf("%lld\n", arr1[mid - j]);
	}
	else if(j < N2 && mid >= i){
		printf("%lld\n", arr2[mid - i]);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
LL arr1[100005] = { 0 }, arr2[100005] = { 0 };//分别代表优惠券和商品价格

int main()
{
	LL N1, N2, i, j;
	int ret = scanf("%lld", &N1);
	for (i = 0; i < N1; ++i) {
		ret = scanf("%lld", &arr1[i]);
	}
	ret = scanf("%lld", &N2);
	for (i = 0; i < N2; ++i) {
		ret = scanf("%lld", &arr2[i]);
	}
	sort(arr1, arr1 + N1);
	sort(arr2, arr2 + N2);
	LL sum = 0;
	for (i = 0; i < N1 && i < N2; ++i) {//处理负数
		if (arr1[i] < 0 && arr2[i] < 0) {
			sum += arr1[i] * arr2[i];
		}
		else break;
	}
	i = N1 - 1;
	j = N2 - 1;
	while (i >= 0 && j >= 0 && arr1[i] > 0 && arr2[j] > 0){//处理正数
		sum += arr1[i] * arr2[j];
		--i;
		--j;
	}
	printf("%lld", sum);
	return 0;
}
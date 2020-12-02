#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
using namespace std;
int arr[10000] = { 0 };

int main()
{
	int N, i = 0, s = 0, max = INT_MIN, n = 0, j = 0;
	int ret = scanf("%d", &N);
	for (; i < N; ++i)
		ret = scanf("%d",&arr[i]);
	for (i = 0; i < N; ++i)
	{
		s += arr[i];
		if (max < s)
		{
			max = s;//不断寻找最大值
			n = i;//最大序列的右端
		}
		s = s < 0 ? 0 : s;//如果s<0, 则置为0
	}
	int sum = 0;
	for (i = n; i >= 0; --i)
	{
		sum += arr[i];
		if (sum == max)
			j = i;//最大序列的左端，注意要最小左端
	}
	if (max < 0 && N >= 1)
		printf("0 %d %d", arr[0], arr[N-1]);//最大值小于0即代表整个序列全部为负数，输出首尾数
	else printf("%d %d %d", max, arr[j], arr[n]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int n)
{
	if (n == 1 || n == 0)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int L = 0, K = 0, i = 0;
	int ret = scanf("%d %d", &L, &K);
	if (ret != 2)
		return 0;
	getchar();
	int* nums = (int*)calloc(L, sizeof(int));
	if (nums == NULL)
		return 0;
	char c;
	while (i < L)
	{
		c = getchar();
		nums[i++] = c - '0';
	}
	int num = 0, cnt = 0;
	/*for (i = 0; i < L; ++i)
		printf("%d ", nums[i]);*/
	for (i = 0; i < L; ++i)
	{
		num = 0;
		cnt = 0;
		for (int j = i; i + K <= L && j < i + K; ++j)
		{
			num = num * 10 + nums[j];
		}
		int tmp = num;
		while (tmp)
		{
			++cnt;
			tmp /= 10;
		}		
		if (isPrime(num))
		{
			for (int j = 0; j < K-cnt; ++j)
				printf("0");
			printf("%d", num);
			return 0;
		}
	}
	printf("404");
	return 0;
}
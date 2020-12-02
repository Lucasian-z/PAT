#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define SWAP(a,b) { int tmp = a; a = b; b = tmp;}

//本题易错点在于题目给出的第二个分数不一定比第一个小
int get_gcd(int a, int b)
{
	return b == 0 ? a : get_gcd(b, a % b);
}

int compare(int a, int b, int c, int d)
{
	return a * d - b * c;
}

int main()
{
	int N1 = 0, M1 = 0, N2 = 0, M2 = 0, K = 0;
	char c;
	while ((c = getchar())!='/')
	{
		N1 = N1 * 10 + (c - '0');
	}
	while ((c = getchar()) != ' ')
	{
		M1 = M1 * 10 + (c - '0');
	}
	while ((c = getchar()) != '/')
	{
		N2 = N2 * 10 + (c - '0');
	}
	while ((c = getchar()) != ' ')
	{
		M2 = M2 * 10 + (c - '0');
	}
	if (compare(N1, M1, N2, M2) > 0)
	{
		SWAP(N1, N2);
		SWAP(M1, M2);
	}
	//printf("%d %d %d %d\n", N1, M1, N2, M2);
	int ret = scanf("%d", &K);
	if (ret != 1)
		return 0;
	int n = 0;
	for (int i = 1; i < K; ++i)
	{
		if (get_gcd(i, K) == 1 && compare(N1, M1, i, K) < 0 && compare(N2, M2, i, K) > 0)
		{
			if (n)
				printf(" ");
			printf("%d/%d", i, K);
			++n;
		}
	}
	return 0;
}
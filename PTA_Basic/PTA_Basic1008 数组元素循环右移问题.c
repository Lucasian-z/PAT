#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//本题关键在于循环右移的位数可能比N大，故要使M对N取余
void reverse(int a[], int left, int right)
{
	int i = left, j = right, tmp;
	while (i < j)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		++i;
		--j;
	}
}

int main()
{
	int N = 0, M = 0;
	int ret = scanf("%d %d", &N, &M);
	if (ret != 2)
		return 0;
	int* arr = (int*)calloc(N, sizeof(int));
	if (NULL == arr)
		return 0;
	int i = 0;
	while (i < N)
	{
		ret = scanf("%d", &arr[i]);
		if (ret != 1)
			return 0;
		++i;
	}
	M %= N;
	reverse(arr, 0, N - M - 1);
	reverse(arr, N - M, N - 1);
	reverse(arr, 0, N - 1);
	if (N == 1) printf("%d", arr[0]);
	else
	{
		for (i = 0; i < N - 1; ++i)
		{
			printf("%d ", arr[i]);
		}
		printf("%d", arr[i]);
	}
	return 0;
}
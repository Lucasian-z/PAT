#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int N = 0;
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	int* arr = (int*)calloc(N, sizeof(int));
	if (NULL == arr)
		return 0;
	int i = 0;
	for (; i < N; ++i)
	{
		ret = scanf("%d", &arr[i]);
		if (ret != 1)
			return 0;
	}
	qsort(arr, N, sizeof(int), compare);
	double res = arr[0];
	for (i = 1; i < N; ++i)
	{
		res = (res + arr[i]) / 2;
	}
	printf("%d", (int)floor(res));
	return 0;
}
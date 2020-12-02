#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int M = 0, N = 0, i = 0, data = 0, j = 0;
	int ret = scanf("%d %d", &N, &M);
	if (ret != 2)
		return 0;
	int* arr = (int*)calloc(N, sizeof(int));
	if (arr == NULL)
		return 0;
	while (i < M)
	{
		for (j = 0; j < N; ++j)
		{
			ret = scanf("%d", &data);
			if (ret != 1)
				return 0;
			arr[j] += data;
		}
		++i;
	}
	int max = -1;
	for (i = 0; i < N; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}
	int res[1000] = { 0 };//此处数组大小不能过小，因为月饼种类数<=1000
	j = 0;
	for (i = 0; i < N; ++i)
		if (max == arr[i])
			res[j++] = i + 1;
	printf("%d\n", max);
	for (i = 0; i < j; ++i)
	{
		if (i != 0)
			printf(" %d", res[i]);
		else printf("%d", res[i]);
	}
	return 0;
}
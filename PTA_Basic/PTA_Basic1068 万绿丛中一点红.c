#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int M = 0, N = 0, X = 0, i = 0, j = 0;
	int ret = scanf("%d %d %d", &M, &N, &X);
	//getchar();
	if (ret != 3)
		return 0;
	int** arr;
	arr = (int**)calloc(N+2, sizeof(int*));

	for (i = 0; i < N+2; ++i)
	{
		arr[i] = (int*)calloc(M+2, sizeof(int));
	}
	for (i = 1; i < N+1; ++i)
	{
		for (j = 1; j < M+1; ++j)
		{
			ret = scanf("%d", &arr[i][j]);
			if (ret != 1)
				return 0;
		}
	}
	int res[100] = { 0 }, k = 0;

	for (i = 1; i < N + 1; ++i)
	{
		for (j = 1; j < M+ 1; ++j)
		{
			int flag = 1;
			if (abs(arr[i][j] - arr[i - 1][j]) > X && abs(arr[i][j] - arr[i - 1][j - 1]) > X\
				&& abs(arr[i][j] - arr[i - 1][j + 1]) > X && abs(arr[i][j] - arr[i][j - 1]) > X\
				&& abs(arr[i][j] - arr[i][j + 1]) > X && abs(arr[i][j] - arr[i + 1][j - 1]) > X\
				&& abs(arr[i][j] - arr[i + 1][j]) > X && abs(arr[i][j] - arr[i + 1][j + 1]) > X)
			{
				for (int m = 1; m < N + 1; ++m)
					for (int p = 1; p < M + 1; ++p)
						if (i != m && arr[i][j] == arr[m][p])
							flag = 0;
				if (flag)
				{
					res[k++] = j;
					res[k++] = i;
					res[k++] = arr[i][j];
				}
				
			}
		}

	}
	if (k > 3)
		printf("Not Unique\n");
	else if (k == 3)
		printf("(%d, %d): %d\n", res[0], res[1], res[2]);
	else
		printf("Not Exist\n");
	return 0;
}
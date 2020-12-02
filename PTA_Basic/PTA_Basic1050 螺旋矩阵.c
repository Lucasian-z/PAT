#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}
void spiral_matrix(int** matrix, int *arr, int num, int m1, int n1, int m2, int n2)
{
	int i, k = num;
	for (i = n1; i <= n2; ++i)
		matrix[m1][i] = arr[k++];
	for (i = m1 + 1; i <= m2; ++i)
		matrix[i][n2] = arr[k++];
	for (i = n2-1; i >= n1; --i)
		matrix[m2][i] = arr[k++];
	for (i = m2 - 1; n2 > n1 && i > m1; --i)
		matrix[i][n1] = arr[k++];

}
int main()
{
	int N = 0, i = 0;
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	int* arr = (int*)calloc(N, sizeof(int));
	if (NULL == arr)
		return 0;
	for (i = 0; i < N; ++i)
	{
		ret = scanf("%d", &arr[i]);
		if (ret != 1)
			return 0;
	}
	qsort(arr, N, sizeof(int), compare);
	/*for (i = 0; i < N; ++i)
		printf("%d ", arr[i]);*/
	int m = N, n = 1, min_gap = N;
	for (i = N; i > 0 && i >= N/i; --i)
	{
		if (N % i == 0)
		{
			if (min_gap > (i - N /i))
			{
				m = i;
				n = N / m;
				min_gap = m - n;
			}
		}
	}
	int** spiralMatrix = (int**)calloc(m, sizeof(int*));
	for (i = 0; i < m; ++i)
		spiralMatrix[i] = (int*)calloc(n, sizeof(int));
	int num = 0, m1 = 0, n1 = 0, m2 = m - 1, n2 = n - 1;
	for (i = 0; i < (m + 1) / 2; ++i)
	{
		if (n1 > n2 || m1 > m2)
			break;
		spiral_matrix(spiralMatrix, arr, num, m1, n1, m2, n2);
		num += 2 * (m2 - m1 + 1) + 2 * (n2 - n1 + 1) - 4;
		++m1; ++n1; --m2; --n2;
	}
	for (i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j)
				printf(" ");
			printf("%d", spiralMatrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
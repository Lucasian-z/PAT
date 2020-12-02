#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N = 0, M = 0;
	int ret = scanf("%d %d", &N, &M);
	if (ret != 2)
		return 0;
	int* scores = (int*)calloc(M, sizeof(int));
	int* answers = (int*)calloc(M, sizeof(int));
	if (scores == NULL || answers == NULL)
		return 0;
	int i = 0, j = 0;
	while (i < M)
	{
		ret = scanf("%d", &scores[i]);
		if (ret != 1)
			return 0;
		++i;
	}
	for (i = 0; i < M; ++i)
	{
		ret = scanf("%d", &answers[i]);
		if (ret != 1)
			return 0;
	}
	int tmp;
	for (i = 0; i < N; ++i)
	{
		int real_score = 0;
		for (j = 0; j < M; ++j)
		{
			ret = scanf("%d", &tmp);
			if (ret != 1)
				return 0;
			if (tmp == answers[j])
				real_score += scores[j];
		}
		printf("%d\n", real_score);
	}
	return 0;
}
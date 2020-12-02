#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 0, M = 0;
	int ret = scanf("%d %d", &N, &M);
	if (ret != 2)
		return 0;
	int i = 0, teach_score, max = 0, min = 100, cnt = 0, score = 0, sum = 0;
	while (i < N)
	{
		ret = scanf("%d", &teach_score);
		if (ret != 1)
			return 0;
		sum = max = cnt = 0;
		min = 100;
		for (int j = 0; j < N - 1; ++j)
		{
			ret = scanf("%d", &score);
			if (ret != 1)
				return 0;
			if (score >= 0 && score <= M)
			{
				sum += score;
				++cnt;
			}
			else continue;
			if (max < score)
				max = score;
			if (min > score)
				min = score;
		}
		double res = ((double)teach_score + (sum - max - min) / (cnt - 2)) / 2;
		printf("%d\n", (int)(res*10+5)/10);
		++i;
	}
	return 0;
}
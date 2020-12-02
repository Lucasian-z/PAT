#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int T = 0, K = 0;
	int ret = scanf("%d %d", &T, &K);
	if (ret != 2)
		return 0;
	int n1 = 0, n2 = 0, b = 0, t = 0;
	while (K--)
	{
		ret = scanf("%d %d %d %d", &n1, &b, &t, &n2);
		if (ret != 4)
			return 0;
		if (t > T)
		{
			printf("Not enough tokens.  Total = %d.\n", T);
			continue;
		}
		
		if (b == 1 && n2 > n1 || b == 0 && n2 < n1)
		{
			T += t;
			printf("Win %d!  Total = %d.\n", t, T);
		}
		else
		{
			T -= t;
			printf("Lose %d.  Total = %d.\n", t, T);
			if (T <= 0)
			{
				printf("Game Over.\n");
				return 0;
			}
		}
	}
	return 0;
}
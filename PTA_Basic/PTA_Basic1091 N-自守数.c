#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N_num(int m)
{
	int tmp, flag = 1;
	for (int i = 1; i < 10; ++i)
	{
		tmp = m;
		flag = 1;
		int tmp2 = m * m * i;
		while (tmp)
		{
			if (tmp2 % 10 != tmp % 10)
			{
				flag = 0;
				break;
			}
			else {
				tmp2/= 10;
				tmp /= 10;
			}
		}
		if (flag) return i;
	}
	return 0;
}

int main()
{
	int M = 0, i = 0, m = 0;
	int ret = scanf("%d", &M);
	if (ret != 1)
		return 0;
	while (i < M)
	{
		ret = scanf("%d", &m);
		if (ret != 1)
			return 0;
		int n = N_num(m);
		if (n)
			printf("%d %d\n", n, n * m * m);
		else printf("No\n");
		++i;
	}
	return 0;
}
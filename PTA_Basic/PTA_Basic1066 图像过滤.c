#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int M = 0, N = 0, A = 0, B = 0, C = 0, i = 0;
	int ret = scanf("%d %d %d %d %d", &M, &N, &A, &B, &C);
	if (ret != 5)
		return 0;
	int data;
	while (M--)
	{
		for (i = 0; i < N; ++i)
		{
			ret = scanf("%d", &data);
			if (ret != 1)
				return 0;
			if (data <= B && data >= A)
				printf("%03d",C);
			else
				printf("%03d", data);
			if (i != N-1)
				printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
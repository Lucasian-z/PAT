#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A = 0, B = 0;
	int ret = scanf("%d %d", &A, &B);
	if (ret != 2)
		return 0;
	int pro = A * B;
	if (!pro)
		printf("0");
	int flag = 0;
	while (pro)
	{
		if (flag == 0 && pro % 10 == 0);
		else
		{
			printf("%d", pro % 10);
			flag = 1;
		}
			
		pro /= 10;
	}
	return 0;
}
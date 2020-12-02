#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 0;
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	getchar();
	int i = 0, num_cnt = 0, alpha_cnt = 0, cnt = 0, flag = 1;
	char c;
	while (i < N)
	{
		num_cnt = 0, alpha_cnt = 0, cnt = 0, flag = 1;
		while ((c = getchar())!='\n')
		{
			++cnt;
			if (c >= '0' && c <= '9')
				++num_cnt;
			else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
				++alpha_cnt;
			else if (c != '.')
				flag = 0;
		}
		if (cnt < 6)
			printf("Your password is tai duan le.\n");
		else if (!flag)
			printf("Your password is tai luan le.\n");
		else if (alpha_cnt && !num_cnt)
			printf("Your password needs shu zi.\n");
		else if (num_cnt && !alpha_cnt)
			printf("Your password needs zi mu.\n");
		else printf("Your password is wan mei.\n");
		++i;
	}
	return 0;
}
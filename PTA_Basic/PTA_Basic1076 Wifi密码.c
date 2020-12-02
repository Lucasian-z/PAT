#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 0;
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	getchar();
	int i = 0;
	char str[20];
	while (i < N)
	{
		gets(str);
		for (int j = 0; str[j]; ++j)
		{
			if (str[j] == 'T')
			{
				printf("%d",str[j - 2] - 'A' + 1);
				break;
			}
		}
		++i;
	}
	return 0;
}
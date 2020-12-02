#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int M = 0, N = 0, S = 0;
	int ret = scanf("%d %d %d", &M, &N, &S);
	if (ret != 3)
		return 0;
	char** names;
	names = (char**)calloc(M, sizeof(char*));
	int i;
	for (i = 0; i < M; ++i)
	{
		names[i] = (char*)calloc(30, sizeof(char));
	}
	i = 1;
	int k = 0;
	getchar();
	char str[30];
	int flag = 0;
	while (i < M + 1)
	{
		if(i < S)
			gets(str);
		else
		{
			gets(str);

			if ((i - S) % N == 0 || flag == 1)
			{
				flag = 0;
				for (int p = 0; p < k; ++p)
				{
					if (strcmp(names[p], str) == 0)
					{
						flag = 1;
						--i;
						--M;
						break;
					}

				}
				if (flag == 0)
				{
					strcpy(names[k], str);
					++k;
				}
			}
		}

		++i;
	}
	if (k == 0)
		printf("Keep going...\n");
	for (i = 0; i < k; ++i)
		printf("%s\n", names[i]);
	return 0;
}
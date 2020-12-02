#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char pwd[100], c;
	int N = 0, i = 0;
	while ((c = getchar()) != ' ')
	{
		pwd[i++] = c;
	}
	pwd[i] = '\0';
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	char passwd[100];
	int n = 0;
	getchar();
	while (1)
	{
		gets(passwd);
		if (strcmp("#", passwd) == 0)
		{
			break;
		}
		else if(strcmp(pwd, passwd) == 0 && n <= N)
		{
			printf("Welcome in\n");
			break;
		}
		else if (strcmp(pwd, passwd))
		{
			printf("Wrong password: %s\n", passwd);
			++n;
			if (n == N)
			{
				printf("Account locked\n");
				break;
			}
		}
	}
	return 0;
}
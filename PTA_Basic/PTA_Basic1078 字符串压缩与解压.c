#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char str[1001];
	char c;
	int ret = scanf("%c", &c);
	if (ret != 1)
		return 0;
	ret = getchar();
	gets(str);
	int cnt = 1;
	if (c == 'C')
	{
		if (strlen(str) == 1)
			printf("%c", str[0]);
		for (int i = 0; i < strlen(str); ++i)
		{
			if (str[i] != str[i + 1])
			{
				if (cnt > 1)
					printf("%d%c", cnt, str[i]);
				else printf("%c", str[i]);
				
				cnt = 1;
			}
			else ++cnt;
			
		}
	}
	else
	{
		for (int i = 0; i < strlen(str); ++i)
		{
			int cnt = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
				cnt = cnt * 10 + (str[i] - '0');
				++i;
			}
			for (int k = 0; k < cnt; ++k)
				printf("%c", str[i]);
			//++i;
			if (!cnt)
				printf("%c", str[i]);
		}
	}
	return 0;
}
#include <stdio.h>

int main()
{
	int colors[62] = { 0 };
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c <= '9' && c >= '0')
			++colors[c - '0'];
		else if (c <= 'z' && c >= 'a')
			++colors[c - 'a' + 10];
		else
			++colors[c - 'A' + 36];
	}
	int flag = 1, cnt = 0;
	while ((c = getchar()) != '\n')
	{
		if (c <= '9' && c >= '0')
		{
			if (colors[c - '0'])
			{
				--colors[c - '0'];
			}
			else
			{
				flag = 0;
				++cnt;
			}
		}
		else if (c <= 'z' && c >= 'a')
		{
			if (colors[c - 'a'+10])
			{
				--colors[c - 'a'+10];
			}
			else
			{
				flag = 0;
				++cnt;
			}
		}
		else
		{
			if (colors[c - 'A'+36])
			{
				--colors[c - 'A' + 36];
			}
			else
			{
				flag = 0;
				++cnt;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 62; ++i)
		sum += colors[i];
	if (flag)
		printf("Yes %d", sum);
	else
		printf("No %d", cnt);
	return 0;
}
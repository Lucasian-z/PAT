#include <stdio.h>

int main()
{
	int a[96] = { 0 };
	char c;
	for (int i = 0; i < 2; ++i)
	{
		while ((c = getchar()) != '\n')
		{
			if (a[c - ' '] == 0)
			{
				printf("%c", c);
				a[c - ' '] = 1;
			}
		}
	}
	
	/*while ((c = getchar()) != '\n')
	{
		if (a[c - ' '] == 0)
		{
			printf("%c", c);
			a[c - ' '] = 1;
		}
	}*/
	return 0;
}
#include <stdio.h>

int help[3] = { 493, 29, 1 };
void trans(int n)
{
	int i = 0, a = 0, b = 0, c = 0;
	while (n)
	{
		if (n > help[0])
		{
			++a;
			n -= help[0];
		}
		else if (n > help[1])
		{
			++b;
			n -= help[1];
		}
		else
		{
			++c;
			n -= help[2];
		}
	}
	printf("%d.%d.%d", a, b, c);
}
int main()
{
	int P[6] = { 0 };
	char c;
	int i = 0;
	int n = 0;
	while (1)
	{
		c = getchar();
		if (c == '\n')
		{
			P[i++] = n;
			break;
		}
		else if (c != ' ' && c != '.')
		{
			n = n * 10 + (c - '0');
		}
		else
		{
			P[i++] = n;
			n = 0;
		}
	}
	int price = 0, money = 0;
	
	for (i = 0; i < 6; ++i) {
		if (i < 3)
			price += help[i] * P[i];
		else
			money += help[i - 3] * P[i];
	}
	if (price > money)
	{
		printf("-");
		trans(price - money);
	}
	else trans(money - price);
	return 0;
}
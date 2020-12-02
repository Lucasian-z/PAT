#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 0;
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	int i = 0, ID, x, y, maxID = 0, max = 0, minID = 0, min = 20000;
	while (i < N)
	{
		ret = scanf("%d %d %d", &ID, &x, &y);
		if (ret != 3)
			return 0;
		x = abs(x);
		y = abs(y);
		if (x * x + y * y >= max)
		{
			maxID = ID;
			max = x * x + y * y;
		}
		else if (x * x + y * y <= min)
		{
			minID = ID;
			min = x * x + y * y;
		}
		++i;
	}
	printf("%04d %04d", minID, maxID);
	return 0;
}
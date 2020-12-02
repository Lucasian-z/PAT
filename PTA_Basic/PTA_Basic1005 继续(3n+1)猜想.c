#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10000] = { 0 };

int main()
{
	int N = 0;
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	int num = 0;
	while (N--)
	{
		ret = scanf("%d", &num);
		if (ret != 1)
			return 0;
		arr[num] = 1;
	}
	for (int i = 0; i < 10000; ++i)
	{
		if (arr[i] == 1)
		{
			int tmp = i;
			while (tmp != 1)
			{
				if (tmp % 2)
					tmp = (3 * tmp + 1) / 2;
				else tmp /= 2;
				arr[tmp] = 0;
			}
		}
	}
	int res[1000] = { 0 }, k = 0;
	for (int i = 9999; i >= 0; --i)
	{
		if (arr[i])
			res[k++] = i;
	}
	int j = 0;
	while (j < k-1)
	{
		printf("%d ", res[j++]);
	}
	printf("%d", res[j]);
	return 0;
}
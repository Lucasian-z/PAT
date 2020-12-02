#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 0;
	int arr[20000] = { 0 };
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	for (int i = 1; i <= N; ++i)
	{
		arr[i / 2 + i / 3 + i / 5] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < 20000; ++i)
	{
		if (arr[i])
			++cnt;
	}
	printf("%d", cnt);
	return 0;
}
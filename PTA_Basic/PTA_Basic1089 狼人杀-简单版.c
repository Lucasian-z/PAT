#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 0, i = 0, j = 0;
	int arr[101] = { 0 };
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	for (i = 1; i <= N; ++i)
	{
		ret = scanf("%d", &arr[i]);
		if (ret != 1)
			return 0;
	}
	for (i = 1; i < N; ++i)
	{
		for (j = i+1; j <= N; ++j)
		{
			int lie[101] = { 0 }, a[101], res = 0;
			for (int k = 0; k < 101; ++k)
				a[k] = -1;
			a[i] = a[j] = 1;//����i��j������
			for (int k = 1; k <= N; ++k)
			{
				if (arr[k] * a[abs(arr[k])] > 0)//k˵abs(arr[k])�����ˣ���abs(arr[k])�������ˣ�����k˵abs(arr[k])�������ˣ���abs(arr[k])������
					lie[res++] = k;
			}
			if (res == 2 && a[lie[0]] + a[lie[1]] == 0)
			{
				printf("%d %d", i, j);
				return 0;
			}				
		}
	}
	printf("No Solution");
	return 0;
}
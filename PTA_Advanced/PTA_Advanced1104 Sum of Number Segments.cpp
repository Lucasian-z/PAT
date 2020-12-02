#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	int N, i;
	double num, sum = 0;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%lf", &num);
		sum += num * (i + 1) * (N - i);
	}
	printf("%.2f", sum);
	return 0;
}
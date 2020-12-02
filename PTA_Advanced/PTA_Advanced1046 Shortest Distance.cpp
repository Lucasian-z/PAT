#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int d[100010] = { 0 }, dis[100010] = { 0 };
int main()
{
	int N, i, e1, e2, M;
	int ret = scanf("%d", &N);
	int sum = 0;
	for (i = 1; i <= N; ++i) {
		ret = scanf("%d", &d[i]);
		sum += d[i];
		dis[i] = sum;
	}
	ret = scanf("%d", &M);
	for (i = 0; i < M; ++i) {
		ret = scanf("%d%d", &e1, &e2);
		if (e1 > e2) {
			int tmp = e1;
			e1 = e2;
			e2 = tmp;
		}
		int sum1 = dis[e2 - 1] - dis[e1 - 1];
		printf("%d\n", sum1 > (sum - sum1) ? (sum - sum1) : sum1);
	}
	return 0;
}
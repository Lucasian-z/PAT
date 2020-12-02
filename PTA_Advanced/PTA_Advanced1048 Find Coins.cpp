#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int coins[1005] = { 0 };//M²»´óÓÚ1000
int main()
{
	int N, M, i, value;
	int ret = scanf("%d %d", &N, &M);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &value);
		++coins[value];
	}
	for (i = 0; i <= M / 2; ++i) {
		if ((2 * i != M && coins[i] > 0 && coins[M - i] > 0) || (2 * i == M && coins[i] >= 2)) {
			printf("%d %d", i, M - i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	int a[3], b[3], res[3];
	int ret = scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
	ret = scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
	res[2] = (a[2] + b[2]) % 29;
	res[1] = (a[1] + b[1] + (a[2] + b[2]) / 29) % 17;
	res[0] = a[0] + b[0] + (a[1] + b[1] + (a[2] + b[2]) / 29) / 17;
	for (int i = 0; i < 3; ++i) {
		if (i) printf(".");
		printf("%d", res[i]);
	}
	return 0;
}
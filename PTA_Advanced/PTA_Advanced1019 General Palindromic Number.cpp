#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

bool isPalind(int a[], int n) {
	int i = 0, j = n - 1;
	while (i < j) {
		if (a[i] != a[j]) {
			return false;
		}
		++i;
		--j;
	}
	return true;
}

int main() 
{
	int N, b;
	int ret = scanf("%d %d", &N, &b);
	int N_b[1000] = { 0 }, n = 0;
	while (N) {
		N_b[n++] = N % b;
		N /= b;
	}
	if (isPalind(N_b, n)) printf("Yes\n");
	else printf("No\n");
	for (int i = n - 1; i >= 0; --i) {
		if (i != n - 1) printf(" ");
		printf("%d", N_b[i]);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int hashTable[10005] = { 0 }, arr[100005];
int main()
{
	int N, num, i;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &arr[i]);
		if(hashTable[arr[i]] < 2)
			++hashTable[arr[i]];
	}
	for (i = 0; i < N; ++i) {
		if (hashTable[arr[i]] == 1) {
			printf("%d", arr[i]);
			break;
		}
	}
	if (i == N) printf("None");
	return 0;
}
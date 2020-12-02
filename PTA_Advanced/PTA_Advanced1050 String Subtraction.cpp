#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[10005];

int main()
{
	int ret = scanf("%[^\n]", str);//∂¡»Î’˚––
	ret = getchar();
	int hashTable[128] = { 0 };
	char c;
	while ((c = getchar()) != '\n') {
		hashTable[c] = 1;
	}
	for (int i = 0; i < strlen(str); ++i) {
		if (hashTable[str[i]] == 0) {
			printf("%c", str[i]);
		}
	}
	return 0;
}
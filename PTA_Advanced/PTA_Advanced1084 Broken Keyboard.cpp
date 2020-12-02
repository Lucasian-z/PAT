#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	char str[85];
	int hashTable1[128] = { 0 }, hashTable2[128] = { 0 };//hashTable1表示坏键，hashTable2表示没有坏的键
	int ret = scanf("%s", str);
	ret = getchar();
	char c;
	while ((c = getchar()) != '\n') {//最终打出来的字符
		if (islower(c)) c -= 32;//小写-->大写
		hashTable2[c - '0'] = 1;
	}
	for (int i = 0; i < strlen(str); ++i) {
		if (islower(str[i])) str[i] -= 32;
		if (hashTable2[str[i] - '0'] == 0) {//坏键，在hashTable1相应位置置1
			hashTable1[str[i] - '0'] = 1;
		}
	}
	for (int i = 0; i < strlen(str); ++i) {
		if (hashTable1[str[i] - '0'] == 1) {//坏键输出一次后将相应位置置0
			printf("%c", str[i]);
			hashTable1[str[i] - '0'] = 0;
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	char str[85];
	int hashTable1[128] = { 0 }, hashTable2[128] = { 0 };//hashTable1��ʾ������hashTable2��ʾû�л��ļ�
	int ret = scanf("%s", str);
	ret = getchar();
	char c;
	while ((c = getchar()) != '\n') {//���մ�������ַ�
		if (islower(c)) c -= 32;//Сд-->��д
		hashTable2[c - '0'] = 1;
	}
	for (int i = 0; i < strlen(str); ++i) {
		if (islower(str[i])) str[i] -= 32;
		if (hashTable2[str[i] - '0'] == 0) {//��������hashTable1��Ӧλ����1
			hashTable1[str[i] - '0'] = 1;
		}
	}
	for (int i = 0; i < strlen(str); ++i) {
		if (hashTable1[str[i] - '0'] == 1) {//�������һ�κ���Ӧλ����0
			printf("%c", str[i]);
			hashTable1[str[i] - '0'] = 0;
		}
	}
	return 0;
}
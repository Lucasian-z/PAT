#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
//先遍历第一个单词的每个字母，并将其标志设为1，然后再遍历第二个单词的每个字母，
//返回遇到第一个标志为1的字母的地址，如果未遇到，则打印-1
struct
{
	char c;
	int next_addr;
	int flag;
}words[100000];//必须添加cstdio头文件，否则无法编译

int main()
{
	int addr1, addr2, N, i;
	int tmp_addr1, tmp_addr2;
	char ch;
	int ret = scanf("%d %d %d", &addr1, &addr2, &N);
	for (i = 0; i < N; ++i)
	{
		ret = scanf("%d %c %d", &tmp_addr1, &ch, &tmp_addr2);
		words[tmp_addr1].c = ch;
		words[tmp_addr1].next_addr = tmp_addr2;
	}
	do
	{
		words[addr1].flag = 1;
		addr1 = words[addr1].next_addr;
	} while (addr1 != -1);
	while (addr2 != -1)
	{
		if (words[addr2].flag == 1)
		{
			printf("%05d", addr2);
			return 0;
		}
		addr2 = words[addr2].next_addr;
	}
	printf("-1");
	return 0;
}
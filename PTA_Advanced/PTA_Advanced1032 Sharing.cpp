#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
//�ȱ�����һ�����ʵ�ÿ����ĸ���������־��Ϊ1��Ȼ���ٱ����ڶ������ʵ�ÿ����ĸ��
//����������һ����־Ϊ1����ĸ�ĵ�ַ�����δ���������ӡ-1
struct
{
	char c;
	int next_addr;
	int flag;
}words[100000];//�������cstdioͷ�ļ��������޷�����

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
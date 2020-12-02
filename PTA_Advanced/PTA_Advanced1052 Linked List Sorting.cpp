#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int max_num = 100000;
typedef struct
{
	int addr;
	int key;
	int next_addr;
	int flag;
}node;
node list[max_num];

bool cmp(node a, node b)
{
	if (a.flag == 0 || b.flag == 0)
		return a.flag > b.flag;//如果节点无效，放在数组后面
	else return a.key < b.key;
}

int main()
{
	int N, start_addr, i, addr1, addr2, key;
	int ret = scanf("%d %d", &N, &start_addr);
	for (i = 0; i < N; ++i)
	{
		ret = scanf("%d %d %d", &addr1, &key, &addr2);
		list[addr1].key = key;
		list[addr1].next_addr = addr2;
		list[addr1].addr = addr1;
	}
	//遍历有效节点，并将其flag设为1
	addr1 = start_addr;
	int cnt = 0;
	while (addr1 != -1)
	{
		list[addr1].flag = 1;
		addr1 = list[addr1].next_addr;
		++cnt;
	}
	sort(list, list + max_num, cmp);//排序
	if (cnt)
		printf("%d %05d\n", cnt, list[0].addr);
	else printf("0 -1\n");//若无有效节点，则输出0 -1
	for (i = 0; i < cnt; ++i)
	{
		printf("%05d %d ", list[i].addr, list[i].key);
		if (i < cnt - 1)
			printf("%05d\n", list[i + 1].addr);
		else printf("-1\n");	
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
//本题采用事先开辟大数组来读取输入，否则需要遍历数组查找相对顺序，会超时
int addr[100005][2] = { 0 };
int main()
{
	int start_addr, node_cnt, K, tmp_addr;
	cin >> start_addr >> node_cnt >> K;
	tmp_addr = start_addr;
	int i, j;
	int address, data, next_addr;
	for (i = 0; i < node_cnt; ++i)
	{
		int ret = scanf("%d %d %d", &address, &data, &next_addr);
		if (ret != 3)
			return 0;
		addr[address][0] = data;
		addr[address][1] = next_addr;
	}
	i = 0;
	vector<int> ivec;
	while (start_addr != -1)
	{
		if (addr[start_addr][0] < 0)
			ivec.push_back(start_addr);
		start_addr = addr[start_addr][1];
	}
	start_addr = tmp_addr;
	while (start_addr != -1)
	{
		if (addr[start_addr][0] >= 0 && addr[start_addr][0] <= K)
			ivec.push_back(start_addr);
		start_addr = addr[start_addr][1];
	}
	start_addr = tmp_addr;
	while (start_addr != -1)
	{
		if (addr[start_addr][0] > K)
			ivec.push_back(start_addr);
		start_addr = addr[start_addr][1];
	}
	if(ivec.size() == 1)
		printf("%05d %d -1\n", ivec[0], addr[ivec[0]][0]);
	else
	{
		for (i = 0; i < ivec.size() - 1; ++i)
		{
			printf("%05d %d %05d\n", ivec[i], addr[ivec[i]][0], ivec[i + 1]);
		}
		printf("%05d %d -1\n", ivec[i], addr[ivec[i]][0]);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int node_list[100000][2] = { 0 };
int main()
{
	int start_addr, data, next_addr, N, K;
	int ret = scanf("%d %d %d", &start_addr, &N, &K);
	if (ret != 3)
		return 0;
	int i, j, addr;
	for (i = 0; i < N; ++i)
	{
		ret = scanf("%d %d %d", &addr, &data, &next_addr);
		if (ret != 3)
			return 0;
		node_list[addr][0] = data;
		node_list[addr][1] = next_addr;
	}
	addr = start_addr;
	vector<int> ivec;
	while (start_addr != -1)
	{
		ivec.push_back(start_addr);
		start_addr = node_list[start_addr][1];
	}
	if (ivec.size() == 1)
		printf("%05d %d -1\n", ivec[0], node_list[ivec[0]][0]);
	else
	{
		for (i = 0; i < ivec.size() / K; ++i)
		{
			reverse(ivec.begin() + K * i, ivec.begin() + K * i + K);
		}
		for (i = 0; i < ivec.size() - 1; ++i)
		{
			printf("%05d %d %05d\n", ivec[i], node_list[ivec[i]][0], ivec[i + 1]);
		}
		printf("%05d %d -1\n", ivec[i], node_list[ivec[i]][0]);
	}
	return 0;
}
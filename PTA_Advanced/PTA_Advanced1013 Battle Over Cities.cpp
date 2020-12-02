#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
//本题采用邻接矩阵(上三角)存储道路，每沦陷一个城市，则计算剩余城市构成并查集的数量n
//最终结果为n-2
using namespace std;
int cities[1000] = { 0 };
int roads[1000][1000] = { 0 };

//查找并查集的根
int findRoot(int x)
{
	if (cities[x] == 0) return x;
	else
	{
		int tmp = findRoot(cities[x]);
		cities[x] = tmp;//边查边减小并查集的高度
		 return tmp;
	}
}

int main()
{
	int N, M, K, i, m, n;
	int ret = scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < M; ++i)//输入M条道路
	{
		ret = scanf("%d %d", &m, &n);
		roads[m][n] = 1;
	}
	int row, col, uniset_cnt = 0;
	for (i = 0; i < K; ++i)
	{
		uniset_cnt = 0;
		ret = scanf("%d", &m);//输入假设丢失城市编号
		for (row = 1; row <= N; ++row)
		{
			if (row == m)
				continue;
			for (col = 1; col <= N; ++col)
			{
				if (col == m)
					continue;
				if (roads[row][col] == 1)
				{
					int a = findRoot(row), b = findRoot(col);
					if (a != b)//如果row和col不在同一集合，则将col所在集合的根并入row所在集合
						cities[b] = findRoot(a);
				}
			}
		}
		for (n = 1; n <= N; ++n)
			if (cities[n] == 0)
				++uniset_cnt;
		printf("%d\n", uniset_cnt - 2);//-2是因为n个集合只需n-1条边即可连接，而且此处需要去除本身
		fill(cities, cities + 1000, 0);
	}
	return 0;
}
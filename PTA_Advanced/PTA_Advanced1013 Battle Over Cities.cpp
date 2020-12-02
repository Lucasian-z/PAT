#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
//��������ڽӾ���(������)�洢��·��ÿ����һ�����У������ʣ����й��ɲ��鼯������n
//���ս��Ϊn-2
using namespace std;
int cities[1000] = { 0 };
int roads[1000][1000] = { 0 };

//���Ҳ��鼯�ĸ�
int findRoot(int x)
{
	if (cities[x] == 0) return x;
	else
	{
		int tmp = findRoot(cities[x]);
		cities[x] = tmp;//�߲�߼�С���鼯�ĸ߶�
		 return tmp;
	}
}

int main()
{
	int N, M, K, i, m, n;
	int ret = scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < M; ++i)//����M����·
	{
		ret = scanf("%d %d", &m, &n);
		roads[m][n] = 1;
	}
	int row, col, uniset_cnt = 0;
	for (i = 0; i < K; ++i)
	{
		uniset_cnt = 0;
		ret = scanf("%d", &m);//������趪ʧ���б��
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
					if (a != b)//���row��col����ͬһ���ϣ���col���ڼ��ϵĸ�����row���ڼ���
						cities[b] = findRoot(a);
				}
			}
		}
		for (n = 1; n <= N; ++n)
			if (cities[n] == 0)
				++uniset_cnt;
		printf("%d\n", uniset_cnt - 2);//-2����Ϊn������ֻ��n-1���߼������ӣ����Ҵ˴���Ҫȥ������
		fill(cities, cities + 1000, 0);
	}
	return 0;
}
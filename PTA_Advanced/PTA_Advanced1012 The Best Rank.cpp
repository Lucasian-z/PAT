#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int N, M, i, j;
	int ret = scanf("%d %d", &N, &M);
	int id, c, m, e;
	map<int, vector<int>> imap;//存储每个学生的id和分数
	multiset<int> iset[4];//利用multiset自动排名，顺序分别是e，m，c，avg
	for (i = 0; i < N; ++i)
	{
		ret = scanf("%d %d %d %d", &id, &c, &m, &e);
		int avg = (((double)(c + m + e) / 3)*10 + 5) / 10;//算平均分数并四舍五入
		imap[id] = { 100-e, 100-m, 100-c, 100-avg };
		iset[0].insert(100-e);//multiset默认顺序为小-->大,故用100-分数，相对排名一致
		iset[1].insert(100-m);
		iset[2].insert(100-c);
		iset[3].insert(100-avg);
	}
	for (i = 0; i < M; ++i)
	{
		ret = scanf("%d", &id);
		int _min = 2001, cnt = 1, maxi;
		if (imap.find(id) == imap.end())//没有该学生信息
		{
			printf("N/A\n");
			continue;
		}
		for (j = 3; j >= 0; --j)
		{
			cnt = 1;
			auto it = iset[j].lower_bound(imap[id][j]);//在相应iset中查找到第一个>=相应分数的位置
			auto begin = iset[j].begin();
			while (begin != it)//算出上述位置与起始位置的距离，即排名
			{
				++cnt;
				++begin;
			}
			if (_min > cnt)//不能用>=，因为优先级为A > C > M > E
			{
				_min = cnt;
				maxi = j;
			}
		}
		printf("%d ", _min);
		if (maxi == 3)
			printf("A");
		else if (maxi == 2)
			printf("C");
		else if (maxi == 1)
			printf("M");
		else printf("E");
		printf("\n");
	}
	return 0;
}
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
	map<int, vector<int>> imap;//�洢ÿ��ѧ����id�ͷ���
	multiset<int> iset[4];//����multiset�Զ�������˳��ֱ���e��m��c��avg
	for (i = 0; i < N; ++i)
	{
		ret = scanf("%d %d %d %d", &id, &c, &m, &e);
		int avg = (((double)(c + m + e) / 3)*10 + 5) / 10;//��ƽ����������������
		imap[id] = { 100-e, 100-m, 100-c, 100-avg };
		iset[0].insert(100-e);//multisetĬ��˳��ΪС-->��,����100-�������������һ��
		iset[1].insert(100-m);
		iset[2].insert(100-c);
		iset[3].insert(100-avg);
	}
	for (i = 0; i < M; ++i)
	{
		ret = scanf("%d", &id);
		int _min = 2001, cnt = 1, maxi;
		if (imap.find(id) == imap.end())//û�и�ѧ����Ϣ
		{
			printf("N/A\n");
			continue;
		}
		for (j = 3; j >= 0; --j)
		{
			cnt = 1;
			auto it = iset[j].lower_bound(imap[id][j]);//����Ӧiset�в��ҵ���һ��>=��Ӧ������λ��
			auto begin = iset[j].begin();
			while (begin != it)//�������λ������ʼλ�õľ��룬������
			{
				++cnt;
				++begin;
			}
			if (_min > cnt)//������>=����Ϊ���ȼ�ΪA > C > M > E
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
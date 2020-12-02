#include <iostream>
#include <map>
#include <set>

using namespace std;
int main()
{
	int N = 0, M = 0, K = 0;
	cin >> N >> M;
	int i = 0;
	multimap<string, string> incompatible;
	set<string> goods;
	string goods_1, goods_2;
	while (i < N)
	{
		cin >> goods_1 >> goods_2;
		incompatible.insert({ goods_1, goods_2 });
		++i;
	}
	/*for (auto& item : incompatible)
		cout << item.first << " " << item.second << endl;*/
	char ch;
	for (i = 0; i < M; ++i)
	{
		cin >> K;
		goods.clear();
		for (int j = 0; j < K; ++j)
		{
			cin >> goods_1;
			goods.insert(goods_1);
		}
		int flag = 1;
		for (const auto& item : goods)
		{
			auto beg = incompatible.lower_bound(item);
			auto end = incompatible.upper_bound(item);
			for (auto m = beg; m != end; ++m)
			{
				if (goods.find(m->second) != goods.end())
				{
					cout << "No" << endl;
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) cout << "Yes" << endl;
	}
	return 0;
}
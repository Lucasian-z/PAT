#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0, M = 0;
	map<int, int> imap;
	cin >> N;
	int id1 = 0, id2 = 0;
	while (N--)
	{
		cin >> id1 >> id2;
		imap[id1] = id2;
	}
	cin >> M;
	set<int> iset;
	while (M--)
	{
		cin >> id1;
		iset.insert(id1);
	}
	set<int> iset2(iset.begin(), iset.end());
	for (const auto &item : iset)
	{
		if (iset.find(imap[item]) != iset.end())
		{
			iset2.erase(item);
			iset2.erase(imap[item]);
		}
	}
	cout << iset2.size() << endl;
	auto end = --iset2.end();
	for (const auto& item : iset2)
	{
		printf("%05d", item);
		if (item != *end)
			cout << " ";

	}
	return 0;
}
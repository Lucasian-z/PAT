#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str, name;
	set<string> iset;
	vector<vector<string>> ivec;
	int N = 0, M = 0, cnt1 = 0, cnt2 = 0, n = 0;
	cin >> N >> M;
	while (M--)
	{
		cin >> str;
		iset.insert(str);
	}
	ivec.reserve(N);
	int i = 0;
	while (i < N)
	{
		cin >> name;
		vector<string> tmp{name};
		ivec.push_back(tmp);
		cin >> n;
		while (n--)
		{
			cin >> str;
			if (find(iset.begin(), iset.end(), str) != iset.end())
			{
				ivec[i].push_back(str);
				++cnt2;
			}
				
		}
		++i;
	}
	for (const auto& item : ivec)
	{
		if (item.size() > 1)
		{
			++cnt1;
			cout << item[0] << ": ";
			size_t j;
			for (j = 1; j < item.size()-1; ++j)
			{
				cout << item[j] << " ";
			}
			cout << item[j] << endl;
		}
	}
	cout << cnt1 << " " << cnt2 << endl;
	return 0;
}
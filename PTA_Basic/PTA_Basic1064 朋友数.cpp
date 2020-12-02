#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	string input;
	set<int> iset;
	int N = 0;
	cin >> N;
	while (N--)
	{
		cin >> input;
		int num_sum = 0;
		for (const auto& item : input)
		{
			num_sum += item - '0';
		}
		iset.insert(num_sum);
	}
	cout << iset.size() << endl;
	auto end = --iset.end();
	for (auto begin = iset.begin(); begin != end; ++begin)
	{
		cout << *begin << " ";
	}
	if(iset.size() > 0)
		cout << *end << endl;
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

int main()
{
	int N = 0, num = 0, i = 0;
	cin >> N;
	map<int, int> imap;
	while (i < N)
	{
		cin >> num;
		++imap[abs(num - i - 1)];
		++i;
	}
	for (auto it = imap.rbegin(); it != imap.rend(); ++it)
	{
		if (it->second > 1)
			cout << it->first << " " << it->second << endl;
	}
	return 0;
}
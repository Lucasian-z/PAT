#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int d = 0, N = 0, i = 0;
	cin >> d >> N;
	map<char, int> imap;
	string str = to_string(d), res = str;
	for (i = 0; i < N-1; ++i)
	{
		int cnt = 1;
		if (str.size() == 1)
			res += "1";
		else
		{
			for (size_t j = 1; j < str.size(); ++j)
			{
				if (str[j] != str[j - 1])
				{
					res += str[j - 1] + to_string(cnt);
					cnt = 1;
				}
				else
				{
					++cnt;
				}
				if (j == str.size()-1)
					res += str[j] + to_string(cnt);
			}
		}
		if(i == N-2)
			cout << res << endl;
		str = res;
		res = "";
	}
	if (N == 1)
		cout << res << endl;
	return 0;
}
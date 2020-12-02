#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	char c;
	string str;
	set<char> bad_key;
	while ((c = getchar()) != '\n')
	{
		bad_key.insert(c);
	}
	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'Z')
		{
			if (bad_key.find('+') != bad_key.end() || bad_key.find(c) != bad_key.end())
				continue;
			else
				str += c;
		}
		else if (c >= 'a' && c <= 'z')
		{
			if (bad_key.find(c - 32) != bad_key.end())
				continue;
			else
				str += c;
		}
		else
		{
			if (bad_key.find(c) != bad_key.end())
				continue;
			else
				str += c;
		}
	}
	if (str.size() > 0)
		cout << str;
	else cout << endl;
	return 0;
}
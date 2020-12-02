#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, str1, str2, str3;
	cin >> str;
	int i = 0, j = 0;
	str1 = str.substr(0, 2);
	while (str[i] != 'E') ++i;
	str2 = str.substr(3, i-3);
	str3 = str.substr(i + 1);
	/*cout << "str1 = " << str1 << endl
		<< "str2 = " << str2 << endl
		<< "str3 = " << str3 << endl;*/
	if (stoi(str3) > 0)
	{
		if (stoi(str3) < str2.size())
			str2.insert(stoi(str3), ".");
		else if (stoi(str3) > str2.size())
			str2.insert(str2.size(),stoi(str3) - str2.size(), '0');
		//cout << str1 << str2 << str3 << endl;
	}
	else if (stoi(str3) < 0)
	{
		str1.insert(1, -1*stoi(str3), '0');
		str1.insert(2, ".");
		//cout << str1 << str2 << str3 << endl;
	}
	cout << ((str1[0] == '+')?str1.substr(1):str1) << str2 << endl;
	return 0;

}
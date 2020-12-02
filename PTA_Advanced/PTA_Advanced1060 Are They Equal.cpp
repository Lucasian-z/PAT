#include <iostream>
#include <string>
using namespace std;
//本题思路是先把float串依据.分成str1，str2，得到str1去除首0的字符数，即为指数，
//如果指数为0，说明str1全0，则求str2的首0个数，idx为其相反数
//如果没有小数点，则idx为str去除首0的字符数
//然后再将str去除首0和尾0及小数点，得到小数串，若位数小于n则补齐，最后拼成res并返回
string trans(string str, int n)
{
	int len = str.size(), i = 0, j = len - 1;
	string deci, str1, str2;
	int idx = 0;
	int pos = str.find('.');
	if (pos != -1)
	{
		str1 = str.substr(0, pos);
		str2 = str.substr(pos + 1);
		while (i < str1.size() && str1[i] == '0') ++i;
		idx = (str1.substr(i)).size();
		if (!idx)
		{
			for (i = 0; i < str2.size() && str2[i] == '0'; ++i);
			idx = -i;
		}
	}
	else
	{
		while (i < str.size() && str[i] == '0') ++i;
		idx = str.size() - i;
	}
	i = 0;
	j = str.size() - 1;
	while (i < str.size() && (str[i] == '0' || str[i] == '.')) ++i;
	while (j >= 0 && str[j] == '0') --j;
	if (i > j)//不能使用>=，否则3 0.0003会错误
		idx = 0;
	else
		deci = str.substr(i, j - i+1);
	//cout << deci << endl;
	if(deci.find('.') != -1)
		deci.erase(deci.begin() + deci.find('.'));
	if (n > deci.size())
		deci += string(n - deci.size(), '0');
	else deci = deci.substr(0, n);
	string res = "0.";
	res += deci + "*10^" + to_string(idx);
	return res;
}

int main()
{
	int N;
	string A, B;
	cin >> N >> A >> B;
	if (trans(A, N) == trans(B, N))
		printf("YES %s", trans(A, N).c_str());
	else
		printf("NO %s %s", trans(A, N).c_str(), trans(B, N).c_str());
	/*cin >> N >> A;
	cout << trans(A, N) << endl;*/
	
	return 0;
}
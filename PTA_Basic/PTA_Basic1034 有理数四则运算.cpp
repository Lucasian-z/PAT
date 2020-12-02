#include <iostream>
#include <string>
#define SWAP(x, y) { long long tmp = x; x = y; y = tmp; }
using namespace std;

//求两数的最大公约数
long long get_gcd(long long x, long long y)
{
	if (x == 0 || y == 0)
		return 0;
	if (x < y)
		SWAP(x, y);
	long long z = x % y;
	while(z)
	{
		x = y;
		y = z;
		z = x % y;
	}
	return y;
}

string format(long long a, long long b)
{
	string res;
	if (a == 0)
		return "0";
	int flag = 0;
	if (a < 0)
	{
		flag = 1;
		a = -a;
	}
	if (a >= b)
	{
		if (b != 0 && a % b)
			res += to_string(a / b) + " " + format(a % b, b);
		else res = to_string(a / b);
	}
	else
	{
		long long gcd = get_gcd(a, b);
		a /= gcd;
		b /= gcd;
		res += to_string(a) + "/" + to_string(b);
	}
	if (flag)
	{
		res.insert(0, "(-");
		res += ")";
	}
	return res;
}

void comp(long long a, long long b, long long c, long long d)//分别是第一个有理数的分子分母和第二个有理数的分子分母
{
	long long numerator = 0, denominator = 0;
	//加法
	numerator = a * d + b * c;
	denominator = b * d;
	cout << format(a, b) << " + " << format(c, d) << " = " << format(numerator, denominator) << endl;
	//减法 
	numerator = a * d - b * c;
	denominator = b * d;
	cout << format(a, b) << " - " << format(c, d) << " = " << format(numerator, denominator) << endl;
	//乘法
	numerator = a * c;
	denominator = b * d;
	cout << format(a, b) << " * " << format(c, d) << " = " << format(numerator, denominator) << endl;
	//除法
	numerator = a * d;
	denominator = b * c;
	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	if (c == 0)
		cout << format(a, b) << " / " << format(c, d) << " = Inf" << endl;
	else cout << format(a, b) << " / " << format(c, d) << " = " << format(numerator, denominator) << endl;
}

int main()
{
	long long a = 0, b = 0, c = 0, d = 0;
	string str;
	getline(cin, str);
	size_t i = 0;
	for (; str[i] != '/'; ++i);
	a = stoi(str.substr(0, i));
	++i;
	auto j = i;
	for (; str[i] != ' '; ++i);
	b = stoi(str.substr(j, i - j));
	++i;
	j = i;
	for (; str[i] != '/'; ++i);
	c = stoi(str.substr(j, i - j));
	d = stoi(str.substr(i + 1));
	comp(a, b, c, d);
	return 0;
}
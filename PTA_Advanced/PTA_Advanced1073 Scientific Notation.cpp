#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str, res, inte, deci, expo;
	cin >> str;
	int i, j;
	for (i = 0; i < str.size() && str[i] != '.'; ++i);//找到小数点的位置
	inte = str.substr(1, i - 1);//存储整数
	for (j = i; j < str.size() && str[j] != 'E'; ++j);
	deci = str.substr(i + 1, j - i - 1);//存储小数
	expo = str.substr(j + 1);//存储指数
	int exp = stoi(expo);	

	//cout << "exp = " << exp << endl;
	//cout << "deci = " << deci << endl;
	if (str[0] == '-') 
		res = "-";
	if (exp < 0) {//如果指数为负
		res += string(-exp, '0') + inte + deci;
		if (str[0] == '-') {
			res.insert(2, ".");//如果为负，在第二个位置插入小数点
		}
		else res.insert(1, ".");//否则在第一个位置插入小数点
	}
	/*else if (exp == 0) {
		res += inte + "." + deci;
	}*/
	else {
		if (exp > deci.size()) {
			res += inte + deci + string(exp - deci.size(), '0');//补0
		}
		else if (exp < deci.size()) {
			deci.insert(exp, ".");
			//cout << deci << endl;
			res += inte + deci;
		}
		else res += inte + deci;//指数与小数位数相等，直接拼接
	}

	cout << res << endl;
	return 0;
}
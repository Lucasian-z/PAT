#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str, res, inte, deci, expo;
	cin >> str;
	int i, j;
	for (i = 0; i < str.size() && str[i] != '.'; ++i);//�ҵ�С�����λ��
	inte = str.substr(1, i - 1);//�洢����
	for (j = i; j < str.size() && str[j] != 'E'; ++j);
	deci = str.substr(i + 1, j - i - 1);//�洢С��
	expo = str.substr(j + 1);//�洢ָ��
	int exp = stoi(expo);	

	//cout << "exp = " << exp << endl;
	//cout << "deci = " << deci << endl;
	if (str[0] == '-') 
		res = "-";
	if (exp < 0) {//���ָ��Ϊ��
		res += string(-exp, '0') + inte + deci;
		if (str[0] == '-') {
			res.insert(2, ".");//���Ϊ�����ڵڶ���λ�ò���С����
		}
		else res.insert(1, ".");//�����ڵ�һ��λ�ò���С����
	}
	/*else if (exp == 0) {
		res += inte + "." + deci;
	}*/
	else {
		if (exp > deci.size()) {
			res += inte + deci + string(exp - deci.size(), '0');//��0
		}
		else if (exp < deci.size()) {
			deci.insert(exp, ".");
			//cout << deci << endl;
			res += inte + deci;
		}
		else res += inte + deci;//ָ����С��λ����ȣ�ֱ��ƴ��
	}

	cout << res << endl;
	return 0;
}
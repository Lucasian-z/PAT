#include <iostream>
#include <string>

using namespace std;

int main()
{
	string hen, A, B;
	cin >> hen >> A >> B;
	if (A.size() < B.size())
		A.insert(0, B.size() - A.size(), '0');
	else B.insert(0, A.size() - B.size(), '0');
	string res;
	int i = A.size()-1;
	int j = hen.size()-1;
	//cout << A << " " << B << endl;
	int carry = 0;
	while (i >= 0)
	{
		int tmp = (A[i] - '0') + (B[i] - '0') + carry;
		//cout << tmp << endl;
		if (hen[j] == '0')
		{
			carry = tmp / 10;
			tmp %= 10;
		}
			
		else
		{
			carry = tmp / (hen[j]-'0');
			tmp %= (hen[j] - '0');
		}
		res += (tmp + '0');
		//cout << res << endl;
		--i;
		--j;
	}
	if (carry)
		res += (carry+'0');
	i = res.size() - 1;

	while (i >= 0 && res[i] == '0') --i;
	if (i >= 0)
		for (; i >= 0; --i)
			cout << res[i];
	else cout << "0";
	return 0;
}
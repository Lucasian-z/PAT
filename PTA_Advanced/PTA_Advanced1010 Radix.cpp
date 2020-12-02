#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long toNum(char c)
{
	int num;
	if (c >= '0' && c <= '9')
		num = c - '0';
	else num = c - 'a' + 10;
	return num;
}
long long trans(string n_str, long long radix)//��radix������ת��Ϊʮ������
{
	long long tmp = 1, sum = 0;
	for (int i = n_str.size() - 1; i >= 0; --i)
	{
		sum += tmp * toNum(n_str[i]);
		tmp *= radix;
		if (sum < 0 || tmp < 0)//������������-1
			return -1;
	}
	return sum;
}

int main()
{
	string N1, N2;
	int tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	long long l, r, mid, base;
	if (tag == 2)
		swap(N1, N2);
	l = 2;
	base = r = trans(N1, radix);//�ұ߽�Ϊ��׼��
	for (auto& item : N2)
	{
		l = max(l, toNum(item) + 1);//��߽�Ϊ��ͽ�����
	}
	while (r >= l)//���ö��ַ�������ʱ
	{
		mid = (l + r) >> 1;
		long long t = trans(N2, mid);
		if (t >= base || t < 0)//�˴���=��ԭ������ĿҪ�������С����
			r = mid - 1;
		else l = mid + 1;

	}
	if (trans(N2, l) == base)//l��֤����Ҫ��Ľ����С
		cout << l;
	else
		printf("Impossible");
	return 0;
}
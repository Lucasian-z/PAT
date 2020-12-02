#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
//���Ƚ���һ�е�ָ����ϵ����double����洢�� �ڶ���ÿ����һ��ʱ�ͽ�����ۼ���map��
//������ε������map
int main()
{
	int K, i, expon;
	map<int, double> res;
	double coeffs[1001] = { 0 }, coeff;
	int ret = scanf("%d", &K);
	for (i = 0; i < K; ++i)
	{
		ret = scanf("%d %lf", &expon, &coeff);//�ֱ�Ϊָ����ϵ��
		coeffs[expon] = coeff;
	}
	ret = scanf("%d", &K);
	for (i = 0; i < K; ++i)
	{
		ret = scanf("%d %lf", &expon, &coeff);
		for (int j = 0; j < 1001; ++j)
		{
			if (fabs(coeffs[j]) > 0)
			{
				res[j + expon] += coeff * coeffs[j];
			}
		}
	}
	int cnt = 0;
	for (auto& item : res)
	{
		if (fabs(item.second) > 0)
			++cnt;
	}
	cout << cnt;
	if (cnt > 0)
	{
		for (auto it = res.rbegin(); it != res.rend(); ++it)
		{
			if (fabs(it->second) > 0)
			{
				printf(" %d %.1f", it->first, it->second);
			}
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
//首先将第一行的指数和系数用double数组存储， 第二行每输入一项时就将结果累加至map中
//最后依次倒序输出map
int main()
{
	int K, i, expon;
	map<int, double> res;
	double coeffs[1001] = { 0 }, coeff;
	int ret = scanf("%d", &K);
	for (i = 0; i < K; ++i)
	{
		ret = scanf("%d %lf", &expon, &coeff);//分别为指数和系数
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
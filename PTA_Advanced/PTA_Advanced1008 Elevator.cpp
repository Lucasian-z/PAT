#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//�״�����ڲ���ͬһ¥���һ������ݣ����Ƿֱ�����ݣ���ÿ����5s
int main()
{
	int N = 0, i = 0;
	int ret = scanf("%d", &N);
	int pre = 0, flr, sum_time = 0;//��ʼ¥��, ��ǰ¥�㣬 ��ʱ��
	for (; i < N; ++i)
	{
		ret = scanf("%d", &flr);
		if (flr > pre)
			sum_time += (flr - pre) * 6 + 5;
		else
			sum_time += (pre - flr) * 4 + 5;
		pre = flr;
	}
	printf("%d", sum_time);
	return 0;
}
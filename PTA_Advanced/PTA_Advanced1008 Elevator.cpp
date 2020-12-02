#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//易错点在于并非同一楼层的一起出电梯，而是分别出电梯，且每人有5s
int main()
{
	int N = 0, i = 0;
	int ret = scanf("%d", &N);
	int pre = 0, flr, sum_time = 0;//初始楼层, 当前楼层， 总时间
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
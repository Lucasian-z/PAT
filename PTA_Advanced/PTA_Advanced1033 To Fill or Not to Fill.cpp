#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct info {
	double price, dis;//油价及距离
}gasStations[505];

bool cmp(info a, info b) {//排序规则
	return a.dis < b.dis;
}

int main()
{
	int N, i;
	double D, D_avg, C;
	int ret = scanf("%lf %lf %lf %d", &C, &D, &D_avg, &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%lf %lf", &gasStations[i].price, &gasStations[i].dis);
	}
	double gas = 0, spend = 0;//分别表示当前油量及花费
	gasStations[i].price = 0, gasStations[i].dis = D;//假设目的地是一个免费的加油站
	sort(gasStations, gasStations + N + 1, cmp);
	if (gasStations[0].dis > 0) {//起点没有加油站
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	int now = 0;
	while (now < N) {
		int minP = -1;
		double priceMin = 1000000;//代表无穷大
		for (i = now + 1; i < N + 1 && gasStations[i].dis - gasStations[now].dis <= C * D_avg; ++i) {
			//找到可达范围内价格最低
			if (gasStations[i].price < priceMin) {
				minP = i;
				priceMin = gasStations[i].price;
				if (priceMin < gasStations[now].price) break;
			}
		}
		if (minP == -1) break;//如果可达范围内没有加油站，则退出循环
		double gasNeed = (gasStations[minP].dis - gasStations[now].dis) / D_avg;//去下一个加油站需要的油量
		if (priceMin > gasStations[now].price) {//当前加油站价格最低
			spend += (C - gas) * gasStations[now].price;//加满油
			gas = C - gasNeed;
		}
		else {			
			if (gas >= gasNeed) {//油够
				gas -= gasNeed;
			}
			else {//油不够
				spend += (gasNeed - gas) * gasStations[now].price;
				gas = 0;
			}		
		}
		now = minP;
	}
	if (now == N) printf("%.2f\n", spend);
	else printf("The maximum travel distance = %.2f\n", gasStations[now].dis + C * D_avg);
	return 0;
}
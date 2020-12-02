#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
//ע�⣺����double�����ݣ���%lf�����������%f
const int maxn = 1005;

struct Mooncake {
	double storge, values, price;
} Mooncakes[maxn];

bool cmp(Mooncake a, Mooncake b) {
	return a.price > b.price;
}

int main()
{
	int N, D, i;
	int ret = scanf("%d %d", &N, &D);
	for (i = 0; i < N; ++i) {
		ret = scanf("%lf", &Mooncakes[i].storge);//����ÿ���±��Ŀ����
	}
	for (i = 0; i < N; ++i) {
		ret = scanf("%lf", &Mooncakes[i].values);//����ÿ���±����ܼ�
		Mooncakes[i].price = Mooncakes[i].values / Mooncakes[i].storge;
	}
	sort(Mooncakes, Mooncakes + N, cmp);
	double profit = 0;
	for (i = 0; i < N && D > 0; ++i) {
		if (D >= Mooncakes[i].storge) {
			profit += Mooncakes[i].values;
			D -= Mooncakes[i].storge;
		}
		else {
			profit += D * Mooncakes[i].price;
			D = 0;
		}
	}
	printf("%.2f", profit);
	return 0;
}
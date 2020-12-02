#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	char name[10];
	int age;
	int worth;
}billionaires[100005];

bool cmp(info a, info b) {//排序规则
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}

int main()
{
	int N, K, i, M, Amin, Amax;
	int ret = scanf("%d %d", &N, &K);
	for (i = 0; i < N; ++i) {
		ret = scanf("%s %d %d", billionaires[i].name, &billionaires[i].age, &billionaires[i].worth);
	}
	sort(billionaires, billionaires + i, cmp);
	for (i = 0; i < K; ++i) {
		ret = scanf("%d %d %d", &M, &Amin, &Amax);//输入最大个数，最小年龄和最大年龄
		printf("Case #%d:\n", i + 1);
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if (cnt < M && billionaires[j].age >= Amin && billionaires[j].age <= Amax) {
				printf("%s %d %d\n", billionaires[j].name, billionaires[j].age, billionaires[j].worth);
				++cnt;//每输出一个
			}
		}
		if (!cnt) printf("None\n");//若没有符合条件的富人
	}
	return 0;
}
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

bool cmp(info a, info b) {//�������
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
		ret = scanf("%d %d %d", &M, &Amin, &Amax);//��������������С������������
		printf("Case #%d:\n", i + 1);
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if (cnt < M && billionaires[j].age >= Amin && billionaires[j].age <= Amax) {
				printf("%s %d %d\n", billionaires[j].name, billionaires[j].age, billionaires[j].worth);
				++cnt;//ÿ���һ��
			}
		}
		if (!cnt) printf("None\n");//��û�з��������ĸ���
	}
	return 0;
}
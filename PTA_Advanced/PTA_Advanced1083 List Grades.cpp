#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	char name[11];
	char id[11];
	int score;
}Stu[110];

bool cmp(info a, info b) {
	return a.score > b.score;
}

int main()
{
	int N, i;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%s %s %d", Stu[i].name, Stu[i].id, &Stu[i].score);
	}
	sort(Stu, Stu + N, cmp);
	int grade1, grade2;
	ret = scanf("%d %d", &grade1, &grade2);
	int print_cnt = 0;//分数在[grade1, grade2]的个数
	for (i = 0; i < N; ++i) {
		if (Stu[i].score >= grade1 && Stu[i].score <= grade2) {
			++print_cnt;
			printf("%s %s\n", Stu[i].name, Stu[i].id);
		}
	}
	if (!print_cnt)//如果没有
		printf("NONE\n");
	return 0;
}
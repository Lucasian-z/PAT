#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	int id;
	char name[10];
	int grade;
}Stu[100005];

bool cmp1(info a, info b) {//按学id递增排序
	return a.id < b.id;
}

bool cmp2(info a, info b) {//按name递增排序，如果name相等，则按id递增排序
	if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
	else return a.id < b.id;
}

bool cmp3(info a, info b) {//按grade排序，如果grade相等，则按id递增排序
	if (a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}

int main()
{
	int N, i, C;
	int ret = scanf("%d %d", &N, &C);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d %s %d", &Stu[i].id, Stu[i].name, &Stu[i].grade);
	}
	if (C == 1) {
		sort(Stu, Stu + i, cmp1);
	} else if (C == 2) {
		sort(Stu, Stu + i, cmp2);
	} else {
		sort(Stu, Stu + i, cmp3);
	}
	for (i = 0; i < N; ++i) {
		printf("%06d %s %d\n", Stu[i].id, Stu[i].name, Stu[i].grade);
	}
	return 0;
}
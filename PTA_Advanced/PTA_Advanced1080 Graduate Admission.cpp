#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct info {
	int id;//学生编号
	int Ge, Gi, finalG;
	int choices[5];//意向学校
	int rank;//排名
}Stu[40005];

bool cmp(info a, info b) {//排序规则
	if (a.finalG != b.finalG) return a.finalG > b.finalG;
	else return a.Ge > b.Ge;
}
int quota[100];//各个学校的录取名额
int school_last[100];//各个学校录取的最低排名，实时更新
set<int> school[100];//各个学校录取的学生编号

int main()
{
	int N, M, K, i;//分别为学生总数，学校总数，以及意向学校数
	int ret = scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < M; ++i) {//各个学校的录取名额数
		ret = scanf("%d", &quota[i]);
	}
	for (i = 0; i < N; ++i) {
		ret = scanf("%d %d", &Stu[i].Ge, &Stu[i].Gi);
		Stu[i].id = i;
		Stu[i].finalG = Stu[i].Ge + Stu[i].Gi;
		for (int j = 0; j < K; ++j) {
			ret = scanf("%d", &Stu[i].choices[j]);
		}
	}
	//排序
	sort(Stu, Stu + N, cmp);
	Stu[0].rank = 1;
	for (i = 1; i < N; ++i) {
		if (Stu[i].finalG == Stu[i - 1].finalG && Stu[i].Ge == Stu[i - 1].Ge)
			Stu[i].rank = Stu[i - 1].rank;
		else Stu[i].rank = i + 1;
	}
	for (i = 0; i < N; ++i) {//从高到低遍历学生
		for (int j = 0; j < K; ++j) {
			if (quota[Stu[i].choices[j]] > 0) {//如果意向学校还有名额
				school[Stu[i].choices[j]].insert(Stu[i].id);
				--quota[Stu[i].choices[j]];
				school_last[Stu[i].choices[j]] = Stu[i].rank;
				break;
			}
			else if (Stu[i].rank == school_last[Stu[i].choices[j]]) {//即使没有名额但是该生的排名
				school[Stu[i].choices[j]].insert(Stu[i].id);//与这个学校录取的最后一名学生的排名
				break;										//相同，那么该名学生也会被此学校录取
			}
		}
	}
	for (i = 0; i < M; ++i) {
		if (school[i].empty()) printf("\n");//该学校未录取学生，打印空行
		else {
			for (auto it = school[i].begin(); it != school[i].end(); ++it) {
				if (it != school[i].begin()) printf(" ");
				printf("%d", *it);
			}
			printf("\n");
		}
	}
	return 0;
}
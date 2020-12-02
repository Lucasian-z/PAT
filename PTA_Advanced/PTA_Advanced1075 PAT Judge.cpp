#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

struct info {
	int id;
	int score[5];
	int total_score;//总分
	int perfact_num;//完美解题数
	int flag;//是否有通过编译的提交
	info() :id(0), total_score(0), flag(0) {//初始化
		fill(score, score + 5, -1);//没有提交
		perfact_num = 0;
	}
}Pat[10005];

bool cmp(info a, info b) {//排序规则
	if (a.total_score != b.total_score) return a.total_score > b.total_score;
	else if (a.perfact_num != b.perfact_num) return a.perfact_num > b.perfact_num;
	else return a.id < b.id;
}

int main()
{
	int N, K, M, i, id, qNum, score;
	int ret = scanf("%d %d %d", &N, &K, &M);
	int pScore[5] = { 0 };//每题满分
	for (i = 0; i < K; ++i) {
		ret = scanf("%d", &pScore[i]);
	}
	for (i = 0; i < M; ++i) {
		ret = scanf("%d %d %d", &id, &qNum, &score);
		Pat[id - 1].id = id;
		if (score >= 0) Pat[id - 1].flag = 1;//通过编译
		else if (Pat[id - 1].score[qNum - 1] == -1) 
			Pat[id - 1].score[qNum - 1] = 0;//第一次未通过编译

		if (score == pScore[qNum - 1] && Pat[id - 1].score[qNum - 1] < pScore[qNum - 1])//第一次满分
			++Pat[id - 1].perfact_num;
		if (score > Pat[id - 1].score[qNum - 1]) Pat[id - 1].score[qNum - 1] = score;//高分覆盖低分
	}
	for (i = 0; i < N; ++i) {//算出每个人的总分
		for (int j = 0; j < K; ++j) {
			if (Pat[i].score[j] > 0) {
				Pat[i].total_score += Pat[i].score[j];
			}
		}
	}
	sort(Pat, Pat + N, cmp);
	int cnt = 1;
	for (i = 0; i < N; ++i) {
		if (i > 0 && Pat[i].total_score != Pat[i - 1].total_score) cnt = i + 1;
		if (Pat[i].flag) {//如果需要打印
			printf("%d %05d %d", cnt, Pat[i].id, Pat[i].total_score);
			for (int j = 0; j < K; ++j) {
				if (Pat[i].score[j] != -1)
					printf(" %d", Pat[i].score[j]);
				else printf(" -");
			}
			printf("\n");
		}
	}
	return 0;
}
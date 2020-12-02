#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	char id[14];
	int score;
	int localNum;//地区序号
	int localRank;//地区排名
}testee[30005];

bool cmp(info a, info b) {
	if (a.score != b.score) return a.score > b.score;//依分数排名
	else return strcmp(a.id, b.id) < 0;//分数相同则把学号小的排在前面
}

int main()
{
	int N, i, K, num = 0;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &K);
		for (int j = 0; j < K; ++j) {//输入每个地区考生的考试结果
			ret = scanf("%s %d", &testee[num].id, &testee[num].score);
			testee[num].localNum = i + 1;//地区序号
			++num;
		}
		sort(testee + num - K, testee + num, cmp);//给每个地区的考试结果进行排序
		
		testee[num - K].localRank = 1;//该地区第一名
		for (int r = num - K + 1; r < num; ++r) {//更新地区排名
			if (testee[r].score == testee[r - 1].score) {//如果分数与上一名相同，则排名也相同
				testee[r].localRank = testee[r - 1].localRank;
			}
			else testee[r].localRank = r - (num - K) + 1;
		}
	}
	//总排序
	sort(testee, testee + num, cmp);
	printf("%d\n", num);
	int cnt = 1;
	for (i = 0; i < num; ++i) {//输出信息
		if (i > 0 && testee[i].score != testee[i -1].score) {
			cnt = i + 1;
		}
		printf("%s %d %d %d\n", testee[i].id, cnt, testee[i].localNum, testee[i].localRank);
	}
	return 0;
}
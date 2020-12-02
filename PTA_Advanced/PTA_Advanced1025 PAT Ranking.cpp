#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	char id[14];
	int score;
	int localNum;//�������
	int localRank;//��������
}testee[30005];

bool cmp(info a, info b) {
	if (a.score != b.score) return a.score > b.score;//����������
	else return strcmp(a.id, b.id) < 0;//������ͬ���ѧ��С������ǰ��
}

int main()
{
	int N, i, K, num = 0;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &K);
		for (int j = 0; j < K; ++j) {//����ÿ�����������Ŀ��Խ��
			ret = scanf("%s %d", &testee[num].id, &testee[num].score);
			testee[num].localNum = i + 1;//�������
			++num;
		}
		sort(testee + num - K, testee + num, cmp);//��ÿ�������Ŀ��Խ����������
		
		testee[num - K].localRank = 1;//�õ�����һ��
		for (int r = num - K + 1; r < num; ++r) {//���µ�������
			if (testee[r].score == testee[r - 1].score) {//�����������һ����ͬ��������Ҳ��ͬ
				testee[r].localRank = testee[r - 1].localRank;
			}
			else testee[r].localRank = r - (num - K) + 1;
		}
	}
	//������
	sort(testee, testee + num, cmp);
	printf("%d\n", num);
	int cnt = 1;
	for (i = 0; i < num; ++i) {//�����Ϣ
		if (i > 0 && testee[i].score != testee[i -1].score) {
			cnt = i + 1;
		}
		printf("%s %d %d %d\n", testee[i].id, cnt, testee[i].localNum, testee[i].localRank);
	}
	return 0;
}
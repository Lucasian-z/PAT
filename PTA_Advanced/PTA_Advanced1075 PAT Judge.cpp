#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

struct info {
	int id;
	int score[5];
	int total_score;//�ܷ�
	int perfact_num;//����������
	int flag;//�Ƿ���ͨ��������ύ
	info() :id(0), total_score(0), flag(0) {//��ʼ��
		fill(score, score + 5, -1);//û���ύ
		perfact_num = 0;
	}
}Pat[10005];

bool cmp(info a, info b) {//�������
	if (a.total_score != b.total_score) return a.total_score > b.total_score;
	else if (a.perfact_num != b.perfact_num) return a.perfact_num > b.perfact_num;
	else return a.id < b.id;
}

int main()
{
	int N, K, M, i, id, qNum, score;
	int ret = scanf("%d %d %d", &N, &K, &M);
	int pScore[5] = { 0 };//ÿ������
	for (i = 0; i < K; ++i) {
		ret = scanf("%d", &pScore[i]);
	}
	for (i = 0; i < M; ++i) {
		ret = scanf("%d %d %d", &id, &qNum, &score);
		Pat[id - 1].id = id;
		if (score >= 0) Pat[id - 1].flag = 1;//ͨ������
		else if (Pat[id - 1].score[qNum - 1] == -1) 
			Pat[id - 1].score[qNum - 1] = 0;//��һ��δͨ������

		if (score == pScore[qNum - 1] && Pat[id - 1].score[qNum - 1] < pScore[qNum - 1])//��һ������
			++Pat[id - 1].perfact_num;
		if (score > Pat[id - 1].score[qNum - 1]) Pat[id - 1].score[qNum - 1] = score;//�߷ָ��ǵͷ�
	}
	for (i = 0; i < N; ++i) {//���ÿ���˵��ܷ�
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
		if (Pat[i].flag) {//�����Ҫ��ӡ
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
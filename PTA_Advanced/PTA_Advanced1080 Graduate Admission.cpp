#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

struct info {
	int id;//ѧ�����
	int Ge, Gi, finalG;
	int choices[5];//����ѧУ
	int rank;//����
}Stu[40005];

bool cmp(info a, info b) {//�������
	if (a.finalG != b.finalG) return a.finalG > b.finalG;
	else return a.Ge > b.Ge;
}
int quota[100];//����ѧУ��¼ȡ����
int school_last[100];//����ѧУ¼ȡ�����������ʵʱ����
set<int> school[100];//����ѧУ¼ȡ��ѧ�����

int main()
{
	int N, M, K, i;//�ֱ�Ϊѧ��������ѧУ�������Լ�����ѧУ��
	int ret = scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < M; ++i) {//����ѧУ��¼ȡ������
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
	//����
	sort(Stu, Stu + N, cmp);
	Stu[0].rank = 1;
	for (i = 1; i < N; ++i) {
		if (Stu[i].finalG == Stu[i - 1].finalG && Stu[i].Ge == Stu[i - 1].Ge)
			Stu[i].rank = Stu[i - 1].rank;
		else Stu[i].rank = i + 1;
	}
	for (i = 0; i < N; ++i) {//�Ӹߵ��ͱ���ѧ��
		for (int j = 0; j < K; ++j) {
			if (quota[Stu[i].choices[j]] > 0) {//�������ѧУ��������
				school[Stu[i].choices[j]].insert(Stu[i].id);
				--quota[Stu[i].choices[j]];
				school_last[Stu[i].choices[j]] = Stu[i].rank;
				break;
			}
			else if (Stu[i].rank == school_last[Stu[i].choices[j]]) {//��ʹû������Ǹ���������
				school[Stu[i].choices[j]].insert(Stu[i].id);//�����ѧУ¼ȡ�����һ��ѧ��������
				break;										//��ͬ����ô����ѧ��Ҳ�ᱻ��ѧУ¼ȡ
			}
		}
	}
	for (i = 0; i < M; ++i) {
		if (school[i].empty()) printf("\n");//��ѧУδ¼ȡѧ������ӡ����
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
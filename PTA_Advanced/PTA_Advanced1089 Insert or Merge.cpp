#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> ivec) {//��ӡvector
	for (int i = 0; i < ivec.size(); ++i) {
		if (i) printf(" ");
		printf("%d", ivec[i]);
	}
	printf("\n");
}

int main()
{
	int N, i, num;
	vector<int> oriSeq, nowSeq;//�ֱ�洢ԭʼ���к͵�ǰ����
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &num);
		oriSeq.push_back(num);
	}
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &num);
		nowSeq.push_back(num);
	}
	int interval = 2;
	while (interval < N) {
		for (i = 0; i + interval <= N; i += interval) {
			sort(oriSeq.begin() + i, oriSeq.begin() + i + interval);//ģ��鲢����
		}
		sort(oriSeq.begin() + i, oriSeq.begin() + N);//�Բ���interval���ֽ�������
		interval *= 2;
		if (oriSeq == nowSeq) {
			for (i = 0; i + interval <= N; i += interval) {//�ٽ���һ�ֹ鲢����
				sort(oriSeq.begin() + i, oriSeq.begin() + i + interval);
			}
			sort(oriSeq.begin() + i, oriSeq.begin() + N);
			printf("Merge Sort\n");
			print(oriSeq);//��ӡ
			return 0;
		}
	}
	printf("Insertion Sort\n");//������ǹ鲢����
	for (i = 0; i < N - 1 && nowSeq[i + 1] >= nowSeq[i]; ++i);
	//����һ�ֲ�������
	int tmp = nowSeq[i + 1];
	while (i >= 0 && nowSeq[i] > tmp) {
		nowSeq[i + 1] = nowSeq[i];
		--i;
	}
	nowSeq[i + 1] = tmp;
	print(nowSeq);
	return 0;
}
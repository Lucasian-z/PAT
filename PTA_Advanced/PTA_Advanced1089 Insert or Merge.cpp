#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> ivec) {//打印vector
	for (int i = 0; i < ivec.size(); ++i) {
		if (i) printf(" ");
		printf("%d", ivec[i]);
	}
	printf("\n");
}

int main()
{
	int N, i, num;
	vector<int> oriSeq, nowSeq;//分别存储原始序列和当前序列
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
			sort(oriSeq.begin() + i, oriSeq.begin() + i + interval);//模拟归并排序
		}
		sort(oriSeq.begin() + i, oriSeq.begin() + N);//对不足interval部分进行排序
		interval *= 2;
		if (oriSeq == nowSeq) {
			for (i = 0; i + interval <= N; i += interval) {//再进行一轮归并排序
				sort(oriSeq.begin() + i, oriSeq.begin() + i + interval);
			}
			sort(oriSeq.begin() + i, oriSeq.begin() + N);
			printf("Merge Sort\n");
			print(oriSeq);//打印
			return 0;
		}
	}
	printf("Insertion Sort\n");//如果不是归并排序
	for (i = 0; i < N - 1 && nowSeq[i + 1] >= nowSeq[i]; ++i);
	//进行一轮插入排序
	int tmp = nowSeq[i + 1];
	while (i >= 0 && nowSeq[i] > tmp) {
		nowSeq[i + 1] = nowSeq[i];
		--i;
	}
	nowSeq[i + 1] = tmp;
	print(nowSeq);
	return 0;
}
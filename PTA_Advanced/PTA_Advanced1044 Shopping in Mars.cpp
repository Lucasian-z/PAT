#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

long long arr[100005] = { 0 };
int idx[100005] = { 0 };//�����±�
int main()
{
	int N, M, i, num, cnt = 0;
	int ret = scanf("%d%d", &N, &M);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &num);
		arr[i + 1] = arr[i] + num;
	}
	int flag = 0, MIN = 100000000;//flag�����Ƿ����ǡ�ø�Ǯ�ķ�Χ�ı�־
	for (i = 0; i <= N; ++i) {
		if (arr[i] >= M) {
			//Ѱ��arr[i]-M�Ƿ���ڣ�������������λ��
			int left = 0, right = i;
			while (left <= right) {
				int mid = (left + right) >> 1;
				if (arr[mid] > arr[i] - M) right = mid - 1;
				else left = mid + 1;
			}
			if (left > 0 && arr[left - 1] == arr[i] - M) {
				printf("%d-%d\n", left, i);
				flag = 1;
			}			
			else if (arr[left] > arr[i] - M) {
				if (MIN >= arr[i] - arr[left - 1]) {//������=
					MIN = arr[i] - arr[left - 1];
					idx[cnt++] = left;
				}
			}
		}
	}
	if (!flag) {		
		for (int j = 0; j < cnt; ++j) {
			int sum = 0;
			for (int k = idx[j]; k <= N; ++k) {
				sum += arr[k] - arr[k - 1];//�ۼ�ԭʼ����
				if (sum == MIN) {//�������Сֵ
					printf("%d-%d\n", idx[j], k);
				}
				else if (sum > MIN) break;//�������ֱ���˳�
			}
		}
	}
	return 0;
}
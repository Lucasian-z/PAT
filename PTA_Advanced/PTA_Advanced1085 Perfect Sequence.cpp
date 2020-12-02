#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[100005] = { 0 };
int main()
{
	long long N, p;
	int ret = scanf("%lld%lld", &N, &p);//�������ʹ��%lld
	int i, MAX_cnt = -1;
	for (i = 0; i < N; ++i) {
		ret = scanf("%lld", &arr[i]);
	}
	sort(arr, arr + N);
	for (i = 0; i < N; ++i) {
		long long bound = arr[i] * p;
		//Ѱ��������λ��
		int left = i, right = N - 1;
		while (left <= right) {//���ֲ��ң��˴�Ҳ��ʹ��upper_bound�������������Ӽ��
			int mid = (left + right) / 2;
			if (arr[mid] > bound) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		MAX_cnt = max(MAX_cnt, left - i);//�����		
	}
	printf("%d", MAX_cnt);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005] = { 0 };
int main()
{
	int N, i, num, cnt = 0, n = 0;//n�����ڱ�λ�ϵ����ָ���
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &num);
		arr[num] = i;//arr�洢��Ӧ�±�
		if (num != 0 && num != i) ++n;
	}
	int j = 1;
	while (n > 0) {
		if (arr[0] == 0) {//0�ڱ�λ
			while (j < N) {//�ҵ�һ�����ڱ�λ�ϵ�����
				if (arr[j] != j) {
					swap(arr[0], arr[j]);
					++cnt;
					break;
				}
				++j;
			}
		}
		while (arr[0] != 0) {//0���ڱ�λ���ͽ�0����λ�õ�����λ����0����λ�ý���
			swap(arr[0], arr[arr[0]]);
			++cnt;
			--n;//���ڱ�λ�ϵ�����1
		}
	}
	printf("%d", cnt);
	return 0;
}
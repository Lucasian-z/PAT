#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>
using namespace std;
int arr[10000] = { 0 };

int main()
{
	int N, i = 0, s = 0, max = INT_MIN, n = 0, j = 0;
	int ret = scanf("%d", &N);
	for (; i < N; ++i)
		ret = scanf("%d",&arr[i]);
	for (i = 0; i < N; ++i)
	{
		s += arr[i];
		if (max < s)
		{
			max = s;//����Ѱ�����ֵ
			n = i;//������е��Ҷ�
		}
		s = s < 0 ? 0 : s;//���s<0, ����Ϊ0
	}
	int sum = 0;
	for (i = n; i >= 0; --i)
	{
		sum += arr[i];
		if (sum == max)
			j = i;//������е���ˣ�ע��Ҫ��С���
	}
	if (max < 0 && N >= 1)
		printf("0 %d %d", arr[0], arr[N-1]);//���ֵС��0��������������ȫ��Ϊ�����������β��
	else printf("%d %d %d", max, arr[j], arr[n]);
	return 0;
}
//��1���ж�ĳ������߱���С�ĸ���+�ұ߱�����ĸ����Ƿ����N-1
//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//
//const int maxn = 100010;
//int arr[maxn] = { 0 };
//int L[maxn] = { 0 }, R[maxn] = { 0 };//�ֱ��ʾ��߱�arr[i]С�����ĸ������ұ߱�arr[i]������ĸ���
//int main()
//{
//	int N, i, cnt = 0;
//	int ret = scanf("%d", &N);
//	int tmp = -1;
//	for (i = 0; i < N; ++i) {
//		ret = scanf("%d", &arr[i]);
//		if (i) {
//			if (arr[i] > tmp) {//���ڵ������вſ��ܳ�Ϊ�ڱ�
//				L[i] = i;
//				tmp = arr[i];
//			}
//		}
//	}
//	tmp = 10000000000;//�����
//	for (i = N - 1; i >= 0; --i) {
//		if (arr[i] < tmp) {//���ұ��������ڵݼ����вſ��ܳ�Ϊ�ڱ�
//			R[i] = N - 1 - i;
//			tmp = arr[i];
//		}
//	}
//	for (i = 0; i < N; ++i) {//�õ��ܸ���
//		if (L[i] + R[i] == N - 1) {//��arr[i]��ߵ�������arr[i]С���ұߵ�������arr[i]��
//			++cnt;
//		}
//	}
//	printf("%d\n", cnt);
//	int flag = 0;
//	for (i = 0; i < N; ++i) {
//		if (L[i] + R[i] == N - 1) {
//			if (flag) printf(" ");
//			printf("%d", arr[i]);
//			flag = 1;
//		}
//	}
//	printf("\n");//�����������
//	return 0;
//}

//��2���ж�ĳ����ߵ�������Ƿ����С�Լ��ұߵ���С���Ƿ������
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int arr[maxn], leftMax[maxn], rightMin[maxn], res[maxn];//�ֱ�洢ԭʼ���ݣ�iλ����ߵ��������iλ��
														//�ұߵ���С���Լ����ս��
int main()
{
	int N, i, cnt = 0;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &arr[i]);
	}
	leftMax[0] = 0;
	for (i = 1; i < N; ++i) {
		leftMax[i] = max(leftMax[i - 1], arr[i - 1]);
	}
	rightMin[N - 1] = 1000000005;
	for (i = N - 2; i >= 0; --i) {
		rightMin[i] = min(rightMin[i + 1], arr[i + 1]);
		
	}
	for (i = 0; i < N; ++i) {
		if (arr[i] > leftMax[i] && arr[i] < rightMin[i]) {//���i��ߵ������С��arr[i]���ұߵ���С��														
			res[cnt++] = arr[i];						  //����arr[i]
		}
	}
	printf("%d\n", cnt);
	for (i = 0; i < cnt; ++i) {
		if (i) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");//�����������
	return 0;
}
//法1，判断某个数左边比它小的个数+右边比它大的个数是否等于N-1
//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//
//const int maxn = 100010;
//int arr[maxn] = { 0 };
//int L[maxn] = { 0 }, R[maxn] = { 0 };//分别表示左边比arr[i]小的数的个数和右边比arr[i]大的数的个数
//int main()
//{
//	int N, i, cnt = 0;
//	int ret = scanf("%d", &N);
//	int tmp = -1;
//	for (i = 0; i < N; ++i) {
//		ret = scanf("%d", &arr[i]);
//		if (i) {
//			if (arr[i] > tmp) {//处于递增数列才可能成为哨兵
//				L[i] = i;
//				tmp = arr[i];
//			}
//		}
//	}
//	tmp = 10000000000;//无穷大
//	for (i = N - 1; i >= 0; --i) {
//		if (arr[i] < tmp) {//从右遍历，处于递减数列才可能成为哨兵
//			R[i] = N - 1 - i;
//			tmp = arr[i];
//		}
//	}
//	for (i = 0; i < N; ++i) {//得到总个数
//		if (L[i] + R[i] == N - 1) {//若arr[i]左边的数都比arr[i]小，右边的数都比arr[i]大
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
//	printf("\n");//必须输出空行
//	return 0;
//}

//法2，判断某数左边的最大数是否比它小以及右边的最小数是否比它大
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int arr[maxn], leftMax[maxn], rightMin[maxn], res[maxn];//分别存储原始数据，i位置左边的最大数，i位置
														//右边的最小数以及最终结果
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
		if (arr[i] > leftMax[i] && arr[i] < rightMin[i]) {//如果i左边的最大数小于arr[i]，右边的最小数														
			res[cnt++] = arr[i];						  //大于arr[i]
		}
	}
	printf("%d\n", cnt);
	for (i = 0; i < cnt; ++i) {
		if (i) printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");//必须输出空行
	return 0;
}
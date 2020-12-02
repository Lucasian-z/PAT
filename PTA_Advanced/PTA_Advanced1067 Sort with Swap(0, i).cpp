#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005] = { 0 };
int main()
{
	int N, i, num, cnt = 0, n = 0;//n代表不在本位上的数字个数
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &num);
		arr[num] = i;//arr存储对应下标
		if (num != 0 && num != i) ++n;
	}
	int j = 1;
	while (n > 0) {
		if (arr[0] == 0) {//0在本位
			while (j < N) {//找到一个不在本位上的数字
				if (arr[j] != j) {
					swap(arr[0], arr[j]);
					++cnt;
					break;
				}
				++j;
			}
		}
		while (arr[0] != 0) {//0不在本位，就将0所在位置的数的位置与0所在位置交换
			swap(arr[0], arr[arr[0]]);
			++cnt;
			--n;//不在本位上的数少1
		}
	}
	printf("%d", cnt);
	return 0;
}
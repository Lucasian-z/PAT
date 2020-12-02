#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

//此题采用暴力法很显然会超时，直接累加每个位置上出现1的次数即可得最终结果

int main()
{
	int N;
	int ret = scanf("%d", &N);
	int left, now, right, res = 0, a = 1;//left代表当前数字左边的值，right代表右边的值，now代表当前数字
	while (N / a) {		
		left = N / (a * 10);
		now = N / a % 10;
		right = N % a;
		if (now == 0) {//如果当前数字等于0，则当其左边0到left-1，及其右边随便取值都可使当前位置为1
			res += left * a;
		}
		else if (now == 1) {//如果当前数字为1，左边0到left-1及右边随便取值加上当前位为1时，右边可取0到right
			res += left * a + right + 1;
		}
		else res += (left + 1) * a;//如果当前数字大于1，左边0到left及右边随便取值
		a *= 10;
	}
	printf("%d", res);
	return 0;
}
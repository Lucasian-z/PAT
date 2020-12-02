#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	int beads[128] = { 0 }, num1 = 0, num2 = 0;//分别代表各个颜色珠子的数目，珠子总数，需要的珠子数目
	char c;
	while ((c = getchar()) != '\n') {
		++beads[c - '0'];
		++num1;
	}
	int emptyCnt = 0;//空缺数
	while ((c = getchar()) != '\n') {
		++num2;
		if (beads[c - '0']) {//还有该颜色的珠子
			--beads[c - '0'];
		}
		else {//没有该颜色的珠子
			++emptyCnt;
		}
	}
	if (emptyCnt) printf("No %d", emptyCnt);
	else printf("Yes %d", num1 - num2);
	return 0;
}
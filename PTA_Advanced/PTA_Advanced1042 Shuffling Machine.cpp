#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
char mp[5] = { 'S', 'H','C','D','J' };
int main()
{
	int cards[54] = { 0 }, order[54] = { 0 };//初始牌面以及顺序
	int i, ret, k;
	ret = scanf("%d", &k);//洗牌轮数
	for (i = 0; i < 54; ++i) {
		cards[i] = i;
		ret = scanf("%d", &order[i]);
	}
	int cards2[54] = { 0 };
	while (k--) {
		for (i = 0; i < 54; ++i) {
			cards2[order[i] - 1] = cards[i];
		}
		for (i = 0; i < 54; ++i) {
			cards[i] = cards2[i];
		}
	}
	for (i = 0; i < 54; ++i) {
		if (i) printf(" ");
		printf("%c%d", mp[cards2[i] / 13], cards2[i] % 13 + 1);
	}
	return 0;
}
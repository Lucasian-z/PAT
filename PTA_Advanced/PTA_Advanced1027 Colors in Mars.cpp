//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//
//void trans(int n) {
//	int res[2];
//	int i = 0;
//	do {
//		res[i++] = n % 13;
//		n /= 13;
//	}while (n);
//	if (i == 1) printf("0");
//	for (int j = i - 1; j >= 0; --j) {
//		if (res[j] > 9) printf("%c", 'A' + res[j] - 10);
//		else printf("%d", res[j]);
//	}
//}
//
//int main()
//{
//	int r, g, b;
//	int ret = scanf("%d%d%d", &r, &g, &b);
//	printf("#");
//	trans(r);
//	trans(g);
//	trans(b);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	char radix[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };
	int r, g, b;
	int ret = scanf("%d%d%d", &r, &g, &b);
	printf("#");
	printf("%c%c", radix[r / 13], radix[r % 13]);
	printf("%c%c", radix[g / 13], radix[g % 13]);
	printf("%c%c", radix[b / 13], radix[b % 13]);
	return 0;
}
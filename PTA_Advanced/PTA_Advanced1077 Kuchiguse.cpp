#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
char str[105][260];
int main()
{
	int N, i, minLength = 300;
	int ret = scanf("%d", &N);
	ret = getchar();
	for (i = 0; i < N; ++i) {
		fgets(str[i], 260, stdin);//gets�ѱ�����,fgets�����س���������תʱ��Ҫ-2
		for (int m = 0, n = strlen(str[i]) - 2; m < n; ++m, --n) {//��ת�ַ���
			char tmp = str[i][m];
			str[i][m] = str[i][n];
			str[i][n] = tmp;
		}
		if (strlen(str[i]) - 1 < minLength) {//strlen�����س�
			minLength = strlen(str[i]) - 1;
		}
	}
	if (!minLength) {//���ڿմ�
		printf("nai\n");
		return 0;
	}
	for (i = 0; i < minLength; ++i) {//��������ַ���
		for (int j = 1; j < N; ++j) {//�ж�ÿ���ַ�����Ӧλ���ַ��Ƿ����
			if (str[0][i] != str[j][i])
			{
				if (i == 0) printf("nai\n");
				else {
					for (j = i - 1; j >= 0; --j) {//�����ӡ
						printf("%c", str[0][j]);
					}
					printf("\n");
				}
				return 0;
			}
		}
	}
	if (i == minLength) {
		for (int j = i - 1; j >= 0; --j) {
			printf("%c", str[0][j]);
		}
		printf("\n");
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	int beads[128] = { 0 }, num1 = 0, num2 = 0;//�ֱ���������ɫ���ӵ���Ŀ��������������Ҫ��������Ŀ
	char c;
	while ((c = getchar()) != '\n') {
		++beads[c - '0'];
		++num1;
	}
	int emptyCnt = 0;//��ȱ��
	while ((c = getchar()) != '\n') {
		++num2;
		if (beads[c - '0']) {//���и���ɫ������
			--beads[c - '0'];
		}
		else {//û�и���ɫ������
			++emptyCnt;
		}
	}
	if (emptyCnt) printf("No %d", emptyCnt);
	else printf("Yes %d", num1 - num2);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

//������ñ���������Ȼ�ᳬʱ��ֱ���ۼ�ÿ��λ���ϳ���1�Ĵ������ɵ����ս��

int main()
{
	int N;
	int ret = scanf("%d", &N);
	int left, now, right, res = 0, a = 1;//left����ǰ������ߵ�ֵ��right�����ұߵ�ֵ��now����ǰ����
	while (N / a) {		
		left = N / (a * 10);
		now = N / a % 10;
		right = N % a;
		if (now == 0) {//�����ǰ���ֵ���0���������0��left-1�������ұ����ȡֵ����ʹ��ǰλ��Ϊ1
			res += left * a;
		}
		else if (now == 1) {//�����ǰ����Ϊ1�����0��left-1���ұ����ȡֵ���ϵ�ǰλΪ1ʱ���ұ߿�ȡ0��right
			res += left * a + right + 1;
		}
		else res += (left + 1) * a;//�����ǰ���ִ���1�����0��left���ұ����ȡֵ
		a *= 10;
	}
	printf("%d", res);
	return 0;
}
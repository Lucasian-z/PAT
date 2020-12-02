#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A[1000] = { 0 };
	int B = 0, i = 0, j = 0;
	char c;
	while ((c = getchar()) != ' ')
	{
		A[i++] = c - '0';
	}
	int ret = scanf("%d", &B);
	if (ret != 1)
		return 0;
	int att = 0, tmp = A[0];
    if(i == 1)
    {
        printf("%d %d", tmp/B,tmp%B);
        return 0;
    }
        
	if (tmp >= B) printf("%d", tmp / B);
	for (j = 1; j < i; ++j)
	{
		att = tmp % B;
		tmp = att * 10 + A[j];
		printf("%d",tmp / B);
	}
	printf(" %d", tmp%B);
	return 0;
}
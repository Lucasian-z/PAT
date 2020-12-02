#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int N = 0, real = 0, imaginary = 0;
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	double max = 0.0;
	while (N--)
	{
		ret = scanf("%d %d", &real, &imaginary);
		if (ret != 2)
			return 0;
		max = max > sqrt(real * real + imaginary * imaginary) ? \
			max : sqrt(real * real + imaginary * imaginary);
	}
	printf("%.2lf", max);
	return 0;
}
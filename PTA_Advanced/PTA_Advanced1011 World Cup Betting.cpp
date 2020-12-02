#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	double arr[9] = { 0 };
	int i, ret;
	for (i = 0; i < 9; ++i)
		ret = scanf("%lf", &arr[i]);
	double profit = 1;
	for (i = 0; i < 9; ++i)
	for (i = 0; i < 9; i += 3)
	{
		auto pos = max_element(arr + i, arr + i + 3);
		if ((pos - arr) % 3 == 0)
			printf("W ");
		else if ((pos - arr) % 3 == 1)
			printf("T ");
		else printf("L ");
		profit *= *pos;
	}
	printf("%.2lf", (profit * 0.65 - 1) * 2);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b;
	int ret = scanf("%d %d", &a, &b);
	if (ret != 2)
		return 0;
	string res = to_string(abs(a + b));
	int flag = (a + b) >= 0 ? 1 : -1;
	if (flag == -1)
		printf("-");
	int i, j = res.size() % 3;
	for (i = 0; i < j; ++i)
	{
		printf("%c", res[i]);
	}
	int k = 0;
	for (; i < res.size(); ++i)
	{
		
		if (i && k % 3 == 0)
			printf(",");
		printf("%c", res[i]);
		++k;
	}
	return 0;
}
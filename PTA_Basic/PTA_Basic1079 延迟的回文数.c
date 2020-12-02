#include <stdio.h>

void reverse(int* a, int n)
{
	for (int i = 0, j = n - 1; i < j; ++i, --j)
	{
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}
int add(int* a, int* b, int n1, int n2, int* res)
{
	int i = n1 - 1, j = n2 - 1, k = 0;
	int data = 0, carry = 0;
	while (i >= 0 && j >= 0)
	{
		data = (a[i] + b[j] + carry);
		carry = data / 10;
		data %= 10;
		res[k++] = data;
		--i;
		--j;
	}
	if (carry)
		res[k++] = carry;
	return k;
}
int isCur(int a[], int n)
{
	if (n == 1)
	{
		return 1;
	}

	int i = 0, j = n - 1;
	while (i < j)
	{
		if (a[0] == 0)
			return 0;
		if (a[i] != a[j])
			return 0;
		++i;
		--j;
	}
	return 1;
}
int main()
{
	int a[2000] = { 0 }, b[2000] = { 0 };
	int i = 0;
	char c;
	int flag = 0;
	while ((c = getchar()) != '\n')
	{
		if (c == '0' && flag == 0)
			continue;
		if (flag == 0) flag = 1;
		a[i] = c - '0';
		b[i] = c - '0';
		++i;
	}
	reverse(b, i);
	int res[2000] = { 0 }, cnt = 0;
	if (isCur(a, i))
	{
		for (int m = i - 1; m >= 0; --m)
		{
			printf("%d", a[m]);
		}
		printf(" is a palindromic number.");
		return 0;
	}

	int k = add(a, b, i, i, res);
	while (!isCur(res, k) && cnt < 10)
	{
		for (int m = 0; m < i; ++m)
			printf("%d", a[m]);
		printf(" + ");
		for (int m = 0; m < i; ++m)
			printf("%d", b[m]);
		printf(" = ");
		for (int m = k - 1; m >= 0; --m)
			printf("%d", res[m]);
		i = 0;
		for (int m = k - 1; m >= 0; --m)
		{
			a[i] = res[m];
			b[i] = res[m];
			++i;
		}
		printf("\n");
		i = k;
		reverse(b, i);
		k = add(a, b, i, i, res);
		++cnt;
	}
	if (isCur(res, k))
	{
		for (int m = 0; m < i; ++m)
			printf("%d", a[m]);
		printf(" + ");
		for (int m = 0; m < i; ++m)
			printf("%d", b[m]);
		printf(" = ");
		for (int m = k - 1; m >= 0; --m)
			printf("%d", res[m]);
		printf("\n");
		for (int m = k - 1; m >= 0; --m)
			printf("%d", res[m]);
		printf(" is a palindromic number.");
	}
	if (cnt >= 10)
		printf("Not found in 10 iterations.");
	return 0;
}
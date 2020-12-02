#include <iostream>
#include <cmath>
using namespace std;
const int maxnum = 1000000;
bool isprime[maxnum] = { 0 };
int prime[100000] = { 0 };//ËØÊıÊı×é
struct
{
	int x;
	int cnt;
}fac[10];
int cnt = 0;
void isPrime()
{
	int i;
	for (i = 2; i < maxnum; ++i)
	{
		if (!isprime[i])
		{
			prime[cnt++] = i;
			for (int j = 2 * i; j < maxnum; j += i)
			{
				isprime[j] = true;
			}
		}
	}
}



int main()
{
	isPrime();
	int N, i = 0, num = 0;
	cin >> N;
	if (N == 1) printf("1=1");
	else
	{
		printf("%d=", N);
		int sqr = sqrt(N);
		for (i = 0; i < cnt && prime[i] <= sqr; ++i)
		{
			if (N % prime[i] == 0)
			{
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while (N % prime[i] == 0)
				{
					++fac[num].cnt;
					N /= prime[i];
				}
				++num;
			}
			
			if (N == 1) break;
		}
		if (N != 1)
		{
			fac[num].x = N;
			fac[num].cnt = 1;
			++num;
		}
	}
	for (i = 0; i < num; ++i)
	{
		if (i > 0) printf("*");
		printf("%d", fac[i].x);
		if (fac[i].cnt > 1)
			printf("^%d", fac[i].cnt);
	}
	return 0;
}
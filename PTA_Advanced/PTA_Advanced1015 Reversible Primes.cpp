#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
//本题题意是求radix进制下reverse_num对应的十进制数是否为素数
using LL = long long;
LL trans(LL x, int radix) {	
	string res;
	LL ans = 0;
	LL tmp = 1;
	while (x)
	{
		res += to_string(x % radix);
		x /= radix;
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i) {
		ans += (res[i] - '0') * tmp;
		tmp *= radix;
	}
	return ans;
}

bool isPrime(LL x) {
	if (x == 1) return false;
	for (int i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0)
			return false;	
	}
	return true;
}

int main()
{
	int N, D;
	while (true)
	{
		cin >> N;
		if (N < 0) break;
		cin >> D;
		if (isPrime(trans(N, D)) && isPrime(N))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
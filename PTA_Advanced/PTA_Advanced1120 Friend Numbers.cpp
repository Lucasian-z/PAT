#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

int trans(char* num) {
	int res = 0;
	for (int i = 0; i < strlen(num); ++i) {
		res += num[i] - '0';
	}
	return res;
}
int main()
{
	int N, i;
	char num[5];
	set<int> res;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%s", num);
		res.insert(trans(num));
	}
	printf("%d\n", res.size());
	for (auto it = res.begin(); it != res.end(); ++it) {
		if (it != res.begin()) printf(" ");
		printf("%d", *it);
	}
	return 0;
}
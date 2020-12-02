#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 10005;
struct info {
	int arrive_time, time;
}Person, Persons[maxn];

bool cmp(info a, info b) {
	return a.arrive_time < b.arrive_time;
}

int main()
{
	int N, K, hh, mm, ss, s;
	int ret = scanf("%d%d", &N, &K);
	int j = 0;
	for (int i = 0; i < N; ++i) {
		ret = scanf("%d:%d:%d %d", &hh, &mm, &ss, &s);
		int t = hh * 3600 + mm * 60 + ss;
		if (t > 17 * 3600) continue;
		Persons[j].arrive_time = t;
		Persons[j++].time = s * 60;
	}
	sort(Persons, Persons + j, cmp);
	vector<int> windows(K, 8 * 3600);//每个窗口的起始时间
	int ans = 0;
	for (int i = 0; i < j; ++i) {
		int mink = 0, mini = windows[0];
		for (int k = 1; k < K; ++k) {
			if (mini > windows[k]) {
				mini = windows[k];
				mink = k;
			}
		}
		if (windows[mink] > Persons[i].arrive_time) {//早到
			ans += windows[mink] - Persons[i].arrive_time;
			windows[mink] += Persons[i].time;
		}
		else {//晚到
			windows[mink] = Persons[i].arrive_time + Persons[i].time;
		}
	}
	printf("%.1f\n", double(ans) / 60 / j);
	return 0;
}
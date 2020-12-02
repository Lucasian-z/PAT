#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

struct info {
	char id[10];
	int time;//距离当天零点秒数
	int status;//0表示in，1表示out
}Cars[10005], Valid[10005];//分别代表所有信息和有效信息

struct ptrCmp {//定义char*比较规则
	bool operator() (const char* s1, const char* s2) const {//必须有最后的const
		return strcmp(s1, s2) < 0;
	}
};
map<char*, int, ptrCmp> parkTIme;//存入车牌号及累积停车时间

bool cmp(info a, info b) {//按车牌号及时间排序
	int flag = strcmp(a.id, b.id);
	if (flag != 0) return flag < 0;
	else if (a.time != b.time) return a.time < b.time;
	else return a.status < b.status;
}

bool cmpTime(info a, info b) {//直接按时间排序
	return a.time < b.time;
}

int main()
{
	int N, K, i, h, m, s;
	char tmp[4];
	int ret = scanf("%d %d", &N, &K);
	for (i = 0; i < N; ++i) {
		ret = scanf("%s %d:%d:%d %s", Cars[i].id, &h, &m, &s, tmp);
		Cars[i].time = h * 3600 + m * 60 + s;
		Cars[i].status = (tmp[0] == 'i') ? 0 : 1;
	}
	sort(Cars, Cars + N, cmp);
	int num = 0, numCar = 0, now = 0, maxTime = -1, time1;
	for (i = 1; i < N; ++i) {
		if (!strcmp(Cars[i - 1].id, Cars[i].id) && Cars[i - 1].status == 0 && Cars[i].status == 1) {
			Valid[num++] = Cars[i - 1];//如果相邻两条信息有效，则加入Valid数组
			Valid[num++] = Cars[i];
			int inTime = Cars[i].time - Cars[i - 1].time;
			parkTIme[Cars[i].id] += inTime;//累积停车时间
			maxTime = max(maxTime, parkTIme[Cars[i].id]);//最大累积停车时间
		}
		else if (Cars[i].status == 1) ++i;
	}
	sort(Valid, Valid + num, cmpTime);

	for (int k = 0; k < K; ++k) {
		ret = scanf("%d:%d:%d", &h, &m, &s);
		time1 = h * 3600 + m * 60 + s;
		while (now < num && Valid[now].time <= time1) {//now指向记录的时间不超过查询时间
			if (Valid[now].status == 0) ++numCar;//如果是进，停车数+1
			else --numCar;//如果是出，停车数-1
			++now;
		}
		printf("%d\n", numCar);
	}
	for (auto it = parkTIme.begin(); it != parkTIme.end(); ++it) {//找出累积最大时间对应的车牌号
		if (maxTime == it->second) {
			printf("%s ", it->first);
		}
	}
	printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
	return 0;
}
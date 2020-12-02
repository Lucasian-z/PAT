#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

bool islate(string time1, string time2)
{
	int s1 = stoi(time1.substr(0, 2)) * 3600 + stoi(time1.substr(3, 2)) * 60 + stoi(time1.substr(6));
	int s2 = stoi(time2.substr(0, 2)) * 3600 + stoi(time2.substr(3, 2)) * 60 + stoi(time2.substr(6));
	return s1 < s2;
}

int main()
{
	string time1, time2, Id, unlock_time = "23:59:59", lock_time = "00:00:00", unlock_Id, lock_Id;
	int M = 0;
	int ret = scanf("%d", &M);
	if (ret != 1)
		return 0;
	int i = 0;
	for (i = 0; i < M; ++i)
	{
		cin >> Id >> time1 >> time2;
		if (!islate(unlock_time, time1))
		{
			unlock_time = time1;
			unlock_Id = Id;
		}
		if (islate(lock_time, time2))
		{
			lock_time = time2;
			lock_Id = Id;
		}
	}
	printf("%s %s", unlock_Id.c_str(), lock_Id.c_str());
	return 0;
}
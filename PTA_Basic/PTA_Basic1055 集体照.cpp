#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	string name;
	int height;
}Stu;

bool compare(Stu a, Stu b)
{
	if (a.height != b.height)
		return a.height < b.height;
	return a.name > b.name;
}

int main()
{
	int N = 0, K = 0, i = 0, j = 0;
	cin >> N >> K;
	vector<Stu> stu;
	string name;
	int height;
	while (i < N)
	{
		cin >> name >> height;
		stu.push_back({ name, height });
		++i;
	}
	sort(stu.begin(), stu.end(), compare);
	/*for (auto& item : stu)
		cout << item.name << " " << item.height << endl;*/
	string res;
	int flag = 1;
	int num = N - (K - 1) * (N / K);
	for (i = 0; i < num; ++i)//最后一排
	{
		if (flag)
		{
			if (!res.empty())
				res += " ";
			res += stu[N - i - 1].name;
			flag = 0;
		}
		else
		{
			string str_tmp = stu[N - i - 1].name + " ";
			res.insert(0, str_tmp);
			flag = 1;
		}
	}
	num = N - num - 1;
	cout << res << endl;
	for (i = 0; i < K - 1; ++i)//剩下K-1排
	{
		res = "";
		flag = 1;
		for (j = 0; j < N / K; ++j)//每排人数
		{
			if (flag)
			{
				if (!res.empty())
					res += " ";
				res += stu[num--].name;
				flag = 0;
			}
			else
			{
				string str_tmp = stu[num--].name + " ";
				res.insert(0, str_tmp);
				flag = 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
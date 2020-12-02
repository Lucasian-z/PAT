#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//本题如果使用cout打印结果极可能超时，故打印大量数据时，最好使用printf
typedef struct
{
	string sId;
	int score;
}Stu;

bool compare(Stu a, Stu b)
{
	if (a.score != b.score)
		return a.score > b.score;
	return a.sId < b.sId;
}

void print(vector<Stu> &ivec, int tye, string instr)
{
	
	if (tye == 1)
	{
		//cout << "instr = " << instr << endl;
		vector<Stu> tmp;
		string t;
		for (const auto& item : ivec)
		{
			t = item.sId[0];
			if (t == instr)
				tmp.push_back(item);
		}
		if (tmp.empty())
			printf("NA\n");
			//cout << "NA" << endl;
		sort(tmp.begin(), tmp.end(), compare);
		for (const auto& item : tmp)
			printf("%s %d\n", item.sId.c_str(), item.score);
			//cout << item.sId << " " << item.score << endl;
	}
	else if (tye == 2)
	{
		int cnt = 0, sum = 0;
		for (const auto& item : ivec)
		{
			if (item.sId.substr(1, 3) == instr)
			{
				++cnt;
				sum += item.score;
			}
		}
		if (!cnt)
			printf("NA\n");
		else
			printf("%d %d\n", cnt, sum);
	}	
	else if (tye == 3)
	{
		vector<Stu> stu;
		int arr[1000] = { 0 };
		for (const auto& item : ivec)
		{
			if (item.sId.substr(4, 6) == instr)
			{
				++arr[stoi(item.sId.substr(1, 3))];
			}
		}
		for (int i = 0; i < 1000; ++i)
		{
			if (arr[i])
				stu.push_back({ to_string(i), arr[i] });
		}
		if (stu.empty())
			printf("NA\n");
		sort(stu.begin(), stu.end(), compare);
		for (const auto& item : stu)
		{
			printf("%s %d\n", item.sId.c_str(), item.score);
			//cout << item.sId << " " << item.score << endl;
		}
	}

}

int main()
{
	int N = 0, M = 0, i = 0;
	cin >> N >> M;
	vector<Stu> students;
	string sid;
	int score;
	for (i = 0; i < N; ++i)
	{
		cin >> sid >> score;
		students.push_back({ sid, score });
	}
	int tye = 0;
	string instr;
	for (i = 0; i < M; ++i)
	{
		cin >> tye >> instr;
		printf("Case %d: %d %s\n", i + 1, tye, instr.c_str());
		print(students,tye, instr);
	}
	return 0;
}
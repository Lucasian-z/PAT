#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	string school;
	int score, num, score1, score2, score3;
}Stu;

bool compare(Stu a, Stu b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else if (a.num != b.num)
		return a.num < b.num;
	else
		return a.school < b.school;
	/*if (a.score < b.score)
		return false;
	else if (a.score > b.score)
		return true;
	else
	{
		if (a.num < b.num)
			return true;
		else if (a.num > b.num)
			return false;
		else
			return a.school < b.school;
	}*/
}

int main()
{
	string sID, school;
	int score;
	map<string, Stu> imap;
	vector<Stu> ivec;
	int N = 0, i = 0;
	cin >> N;
	if (N > 50000)
		ivec.reserve(100000);
	while (i < N)
	{
		cin >> sID >> score >> school;
		if (score > 100 || score < 0)
		{
			++i;
			continue;
		}
		transform(school.begin(), school.end(), school.begin(), ::tolower);
		imap[school].school = school;
		++imap[school].num;
		switch (sID[0])
		{
		case 'B':
			imap[school].score1 += score;
			break;
		case 'A':
			imap[school].score2 += score;
			break;
		case 'T':
			imap[school].score3 += score;
			break;
		default:
			break;
		}
		++i;
	}
	for (auto& item : imap)
	{
		item.second.score = item.second.score1 / 1.5 + item.second.score2 + item.second.score3 * 1.5;
		ivec.push_back({ item.first, item.second.score, item.second.num });
	}
	sort(ivec.begin(), ivec.end(), compare);
	cout << ivec.size() << endl;
	int tmp = 1;
	for (i = 0; i < ivec.size(); ++i)
	{
		if (i == 0 || ivec[i].score == ivec[i - 1].score)
			cout << tmp << " ";
		else if (ivec[i].score != ivec[i - 1].score)
		{
			tmp = i + 1;
			cout << tmp << " ";
		}
		cout << ivec[i].school << " " << ivec[i].score << " " << ivec[i].num << endl;
	}

	return 0;
}
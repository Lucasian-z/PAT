#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef struct
{
	string sId;
	int p_score, mid_score = -1, final_score;
	int sum_score;
}Stu;

bool compare(Stu a, Stu b)
{
	if (a.sum_score > b.sum_score)
		return true;
	else if (a.sum_score < b.sum_score)
		return false;
	else
	{
		return a.sId < b.sId;
	}
}

int main()
{
	vector<Stu> ivec;
	int P = 0, M = 0, N = 0, i = 0;
	cin >> P >> M >> N;
	map<string, int> imap;
	string sID;
	int score = 0, k = 0;
	for (i = 0; i < P; ++i)
	{
		cin >> sID >> score;
		if (score >= 200 && score <= 900)
		{
			ivec.push_back({ sID, score });
			imap[sID] = k++;
		}
			
	}
	for (i = 0; i < M; ++i)
	{
		cin >> sID >> score;
		if (score > 100) continue;
		/*for (size_t j = 0; j < ivec.size(); ++j)
		{
			if (ivec[j].sId == sID)
			{
				ivec[j].mid_score = score;
				break;
			}
		}*/
		auto it = imap.find(sID);
		if (it != imap.end())
		{
			ivec[it->second].mid_score = score;
		}
	}
	for (i = 0; i < N; ++i)
	{
		cin >> sID >> score;
		if (score > 100) continue;
		/*for (size_t j = 0; j < ivec.size(); ++j)
		{
			if (ivec[j].sId == sID)
			{
				ivec[j].final_score = score;
				if (ivec[j].final_score < ivec[j].mid_score)
					ivec[j].sum_score = ((ivec[j].mid_score * 0.4 + ivec[j].final_score * 0.6)*10+5)/10;
				else ivec[j].sum_score = score;
				break;
			}				
		}*/
		auto it = imap.find(sID);
		if (it != imap.end())
		{
			ivec[it->second].final_score = score;
			if (ivec[it->second].final_score < ivec[it->second].mid_score)
				ivec[it->second].sum_score = ((ivec[it->second].mid_score * 0.4\
				+ ivec[it->second].final_score * 0.6) * 10 + 5) / 10;
			else ivec[it->second].sum_score = score;
		}
	}
	sort(ivec.begin(), ivec.end(), compare);
	for (i = 0; i < ivec.size(); ++i)
		if (ivec[i].sum_score >= 60)
		{
			cout << ivec[i].sId << " " << ivec[i].p_score << " " << ivec[i].mid_score\
				 << " " << ivec[i].final_score << " " << ivec[i].sum_score << endl;
		}
	return 0;
}
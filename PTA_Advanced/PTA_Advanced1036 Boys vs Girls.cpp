//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//int main()
//{
//	string name, gender, id, score;
//	int N, i;
//	int ret = scanf("%d", &N);
//	map<int, string> scoreId_Female, scoreId_Male;
//	map<string, string> idName;
//	for (i = 0; i < N; ++i) {
//		cin >> name >> gender >> id >> score;
//		idName[id] = name;
//		if (gender == "M") scoreId_Male[stoi(score)] = id;
//		else scoreId_Female[stoi(score)] = id;
//	}
//	int score1 = -1, score2 = -1;	
//	if (!scoreId_Female.empty()) {
//		auto it1 = scoreId_Female.rbegin();
//		score1 = it1->first;
//		printf("%s %s\n", idName[it1->second].c_str(), it1->second.c_str());
//	}		
//	else printf("Absent\n");
//	
//	if (!scoreId_Male.empty()) {
//		auto it2 = scoreId_Male.begin();
//		score2 = it2->first;
//		printf("%s %s\n", idName[it2->second].c_str(), it2->second.c_str());
//	}
//	else printf("Absent\n");
//
//	if (score1 == -1 || score2 == -1)
//		printf("NA\n");
//	else
//		printf("%d\n", score1 - score2);	
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

struct info {
	char name[12];
	char gender;
	char id[12];
	int score;
}F, M, tmp;

int main()
{
	M.score = 101;
	F.score = -1;
	int N, i;
	int ret = scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		ret = scanf("%s %c %s %d", &tmp.name, &tmp.gender, &tmp.id, &tmp.score);
		if (tmp.gender == 'M') {
			if (tmp.score < M.score) {
				M = tmp;
			}
		}
		else {
			if (tmp.score > F.score) {
				F = tmp;
			}
		}
	}
	if (F.score == -1) printf("Absent\n");
	else printf("%s %s\n", F.name, F.id);
	if (M.score == 101) printf("Absent\n");
	else printf("%s %s\n", M.name, M.id);
	if (F.score == -1 || M.score == 101)
		printf("NA\n");
	else printf("%d\n", F.score - M.score);
	return 0;
}
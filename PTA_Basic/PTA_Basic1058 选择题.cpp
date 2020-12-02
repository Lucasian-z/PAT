#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N, M, i;
	cin >> N >> M;
	string str;
	char c;
	getline(cin, str);
	vector<string> answers;
	for (i = 0; i < M; ++i)
	{
		str = "";
		while ((c = getchar()) != '\n')
		{
			if (c == ' ')
				continue;
			str += c;
		}
		//cout << "str = " << str << endl;
		answers.push_back(str);
	}
	int* wrong_cnt = (int*)calloc(M, sizeof(int));
	int* scores = (int*)calloc(N, sizeof(int));
	if (nullptr == wrong_cnt || nullptr == scores)
		return 0;
	//getline(cin, str);
	
	for (i = 0; i < N; ++i)
	{
		str = "";
		while ((c = getchar()) != '\n')
		{
			if (c == ' ' || c == '(' || c == ')')
				continue;
			str += c;
		}
		int num = 0;
		string str_tmp;
		for (int j = 0; j < M; ++j)
		{
			str_tmp = str.substr(num,str[num]-'0'+1);
			//cout << "str_tmp = " << str_tmp << endl;
			num += (str[num]-'0') + 1;
			if (str_tmp == answers[j].substr(2))
				scores[i] += answers[j][0] - '0';
			else ++wrong_cnt[j];
		}
	}
	for (i = 0; i < N; ++i)
		printf("%d\n", scores[i]);
	int max = 0;
	for (i = 0; i < M; ++i)
	{
		if (max < wrong_cnt[i])
		{
			max = wrong_cnt[i];
		}
	}
	if (max == 0)
		printf("Too simple");
	else
	{
		printf("%d", max);
		for (i = 0; i < M; ++i)
		{
			if (max == wrong_cnt[i])
			{
				printf(" %d", i + 1);
			}				
		}
	}
	return 0;
}
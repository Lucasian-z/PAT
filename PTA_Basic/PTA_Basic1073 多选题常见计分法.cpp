#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	string str;
	getline(cin, str);
	vector<string> ivec;
	int i = 0;
	char c;
	for (i = 0; i < M; ++i)
	{
		str = "";
		while ((c = getchar()) != '\n')
		{
			if (c != ' ')
				str += c;
		}
		ivec.push_back(str);
	}
	/*for (auto& item : ivec)
		cout << item << endl;*/
	double* scores = (double*)calloc(N, sizeof(double));
	int wrong_info[100][5] = { 0 };
	if (nullptr == scores)
		return 0;
	string str_solution, str_answers;
	
	for (i = 0; i < N; ++i)
	{
		str = "";
		while ((c = getchar()) != '\n')
		{
			if (c != ' ' && c != '(' && c != ')')
				str += c;
		}
		int num = 0;
		for (int j = 0; j < M; ++j)
		{
			str_solution = str.substr(num, str[num] - '0' + 1);
			num += (str[num] - '0') + 1;
			str_answers = ivec[j].substr(2);
			int flag = 1;
			for (size_t k = 1; k < str_solution.size(); ++k)
			{
				if (str_answers.find(str_solution[k]) == str_answers.npos)
				{
					++wrong_info[j][str_solution[k] - 'a'];
					flag = 0;
				}
			}
			if (flag == 1 && str_answers[0] == str_solution[0])
				scores[i] += (ivec[j][0]-'0');
			else if(flag == 1 && str_answers[0] > str_solution[0])
				scores[i] += (ivec[j][0] - '0') / 2.0;

			for (size_t k = 1; k < str_answers.size(); ++k)
			{
				if (str_solution.find(str_answers[k]) == str_solution.npos)
				{
					++wrong_info[j][str_answers[k] - 'a'];
				}
			}
		}
	}
	for (i = 0; i < N; ++i)
		printf("%.1f\n", scores[i]);
	int max = 0, maxi;
	for (i = 0; i < M; ++i)
	{
		for (int j = 0; j < 5; ++j)
			if (wrong_info[i][j] > max)
				max = wrong_info[i][j];
	}
	if (!max)
		printf("Too simple");
	else
	{
		for (i = 0; i < M; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				//printf("wrong = %d\n", wrong_info[i][j]);
				if (wrong_info[i][j] == max)
					printf("%d %d-%c\n", max, i + 1, 'a' + j);
			}
		}
	}
	return 0;
}
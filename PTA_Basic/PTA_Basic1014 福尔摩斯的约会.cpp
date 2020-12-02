#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	vector<string> ivec;
	string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	size_t i = 0, j = 0;
	while (i < 4)
	{
		cin >> str;
		ivec.push_back(str);
		++i;
	}
	for (i = 0; i < ivec[0].size() && i < ivec[1].size(); ++i)
		if (ivec[0][i] == ivec[1][i] && ivec[0][i] >= 'A' && ivec[0][i] <= 'G')
		{
			cout << days[(ivec[0][i] - 'A')] << " ";
			break;
		}
			
	for (j = i + 1; j < ivec[0].size() && j < ivec[1].size(); ++j)
		if (ivec[0][j] == ivec[1][j])
			if (ivec[0][j] >= 'A' && ivec[0][j] <= 'N')
			{
				printf("%d:", ivec[0][j]-'A'+10);
				break;
			}
			else if (ivec[0][j] >= '0' && ivec[0][j] <= '9')
			{
				printf("%02d:", ivec[0][j] - '0');
				break;
			}
	for (i = 0; i < ivec[2].size() && i < ivec[3].size(); ++i)
		if (ivec[2][i] == ivec[3][i] && isalpha(ivec[2][i]))
		{
			printf("%02d", i);
			break;
		}
			
	return 0;
}
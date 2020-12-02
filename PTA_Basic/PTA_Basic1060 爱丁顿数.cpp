#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N = 0, i = 0, num;
	cin >> N;
	vector<int> ivec;
	ivec.reserve(N);
	while (i < N)
	{
		cin >> num;
		ivec.push_back(num);
		++i;
	}
	sort(ivec.begin(), ivec.end());
	int cnt = 0;
	for (i = N - 1; i >= 0; --i)
	{
		if (ivec[i] > N - i)
		{
			++cnt;
		}
		else
			break;
	}
	cout << cnt << endl;
	return 0;
}
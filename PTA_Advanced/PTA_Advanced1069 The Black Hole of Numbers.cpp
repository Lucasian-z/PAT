#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

//注意不一定输入4位数，不足4位要在前面补0
int main()
{
	string num, numDup;
	cin >> num;
	if (num.size() < 4) num.insert(0, string(4 - num.size(), '0'));
	numDup = num;	
	do {
		sort(num.begin(), num.end(), cmp);
		sort(numDup.begin(), numDup.end());
		int n1 = stoi(num), n2 = stoi(numDup);
		printf("%04d - %04d = %04d\n", n1, n2, n1 - n2);
		num = to_string(n1 - n2);
		if (num.size() < 4) num.insert(0, string(4 - num.size(), '0'));
		numDup = num;
	} while (num != "6174" && num != "0000");
	return 0;
}
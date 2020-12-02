#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2) {//�������
	return s1 + s2 < s2 + s1;
}
int main()
{
	int N, i;
	cin >> N;
	string num;
	vector<string> ivec;
	for (i = 0; i < N; ++i) {
		cin >> num;
		ivec.push_back(num);
	}
	sort(ivec.begin(), ivec.end(), cmp);
	int k = 0, flag = 0;
	for (auto it1 : ivec) {
		for (auto it2 : it1) {
			if (!flag && it2 != '0') {//���������һ����0����flag��1
				flag = 1;
			}
			if (flag) {
				printf("%c", it2);
			}
		}
	}
	if (!flag) printf("0");//������ս��Ϊ0��Ҫ���0
	return 0;
}
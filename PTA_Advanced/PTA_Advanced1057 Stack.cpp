#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> sta;
const int maxn = 100005;
int block[maxn] = { 0 }, table[maxn] = { 0 };//�ֱ����ÿ��ӵ��Ԫ�ظ�����ÿ��Ԫ�س��ִ���

int findMid(int K) {//������λ��
	int sum = 0, i = 0;
	while (sum + block[i] < K) {//�ۼ�ÿ��Ԫ�ظ���
		sum += block[i];
		++i;
	}
	int j = i * 316;
	while (sum < K) {
		sum += table[j];//�ۼ�Ԫ�س��ִ���
		++j;
	}
	--j;
	return j;
}

int main()
{
	for (int i = 1; i < 9; ++i)
		printf("%d\n", i & (-i));
	int N, data;
	string operation;
	int ret = scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; ++i) {
		getline(cin, operation);
		string op = operation.substr(0, 2);
		if (op == "Pu") {
			data = stoi(operation.substr(5));
			sta.push(data);
			++table[data];
			++block[data / 316];
		}
		else if (op == "Po") {
			if (sta.empty()) {
				printf("Invalid\n");
				continue;
			}
			data = sta.top();
			sta.pop();
			--table[data];
			--block[data / 316];
			printf("%d\n", data);
		}
		else {
			if (sta.empty()) {
				printf("Invalid\n");
				continue;
			}
			if (sta.size() % 2 == 0) {
				printf("%d\n", findMid(sta.size() / 2));
			}
			else printf("%d\n", findMid(sta.size() / 2 + 1));
		}
	}
	return 0;
}
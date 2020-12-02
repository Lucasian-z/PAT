#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 2000;
int matrix[maxn][maxn] = { 0 }, weight[maxn] = { 0 };//权值
int visit[maxn] = { 0 };
int N, K, numNode = 0;
map<string, int> imap1;//name->编号
map<int, string> imap2;//编号->name
map<string, int> res;

void DFS(int u, int &head, int& numCnt, int& sumValue) {//以引用方式传入参数
	visit[u] = 1;//将访问标志置1
	++numCnt;
	if (weight[u] > weight[head])//找出连通块最大值对应的下标
		head = u;
	for (int v = 0; v < numNode; ++v) {
		if (matrix[u][v] > 0) {//如果u,v之间有通话
			sumValue += matrix[u][v];//总值
			matrix[u][v] = matrix[v][u] = 0;//避免重复累加
			if (visit[v] == 0)
				DFS(v, head, numCnt, sumValue);
		}
	}
}

void DFSTreval() {
	for (int i = 0; i < numNode; ++i) {
		int head = i, numCnt = 0, sumValue = 0;//初始化
		if (visit[i] == 0) {
			DFS(i, head, numCnt, sumValue);
			if (numCnt > 2 && sumValue > K) {//如果满足条件，则加入res
				res[imap2[head]] = numCnt;
			}
		}
	}
}

int change(string str) {//返回str对应的int
	if (imap1.find(str) != imap1.end()) {
		return imap1[str];
	}
	else {
		imap1[str] = numNode;
		imap2[numNode] = str;
		return numNode++;//全局变量，表示现有的总人数
	}
}

int main()
{
	int ret = scanf("%d %d", &N, &K);
	int i, time;
	string name1, name2;
	for (i = 0; i < N; ++i) {
		cin >> name1 >> name2 >> time;
		int id1 = change(name1), id2 = change(name2);
		matrix[id1][id2] += time;
		matrix[id2][id1] += time;
		weight[id1] += time;
		weight[id2] += time;
	}
	DFSTreval();
	printf("%d\n", res.size());
	for (const auto& item : res) {
		printf("%s %d\n", item.first.c_str(), item.second);
	}
	return 0;
}
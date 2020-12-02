#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 2000;
int matrix[maxn][maxn] = { 0 }, weight[maxn] = { 0 };//Ȩֵ
int visit[maxn] = { 0 };
int N, K, numNode = 0;
map<string, int> imap1;//name->���
map<int, string> imap2;//���->name
map<string, int> res;

void DFS(int u, int &head, int& numCnt, int& sumValue) {//�����÷�ʽ�������
	visit[u] = 1;//�����ʱ�־��1
	++numCnt;
	if (weight[u] > weight[head])//�ҳ���ͨ�����ֵ��Ӧ���±�
		head = u;
	for (int v = 0; v < numNode; ++v) {
		if (matrix[u][v] > 0) {//���u,v֮����ͨ��
			sumValue += matrix[u][v];//��ֵ
			matrix[u][v] = matrix[v][u] = 0;//�����ظ��ۼ�
			if (visit[v] == 0)
				DFS(v, head, numCnt, sumValue);
		}
	}
}

void DFSTreval() {
	for (int i = 0; i < numNode; ++i) {
		int head = i, numCnt = 0, sumValue = 0;//��ʼ��
		if (visit[i] == 0) {
			DFS(i, head, numCnt, sumValue);
			if (numCnt > 2 && sumValue > K) {//������������������res
				res[imap2[head]] = numCnt;
			}
		}
	}
}

int change(string str) {//����str��Ӧ��int
	if (imap1.find(str) != imap1.end()) {
		return imap1[str];
	}
	else {
		imap1[str] = numNode;
		imap2[numNode] = str;
		return numNode++;//ȫ�ֱ�������ʾ���е�������
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
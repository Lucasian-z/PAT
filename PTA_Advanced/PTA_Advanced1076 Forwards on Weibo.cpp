#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 1010;
struct node {
	int v;//�����
	int layer;//����������
};
vector<node> Adj[maxn];
int visit[maxn] = { 0 };
void BFS(int u, int layer, int &inLayerCnt) {
	fill(visit, visit + maxn, 0);
	queue<node> que;
	node start;
	start.layer = 0;//�׽ڵ������Ϊ0
	start.v = u;
	que.push(start);//�׽ڵ����
	visit[u] = 1;//���֮����ʱ�־��Ϊ1
	while (!que.empty()){
		node tmp = que.front();
		que.pop();
		for (int i = 0; i < Adj[tmp.v].size(); ++i) {//����ÿ���ڵ���ӽڵ㣬���Ϊ���ڵ�+1
			if (visit[Adj[tmp.v][i].v] == 0){
				Adj[tmp.v][i].layer = tmp.layer + 1;
				que.push(Adj[tmp.v][i]);
				if (Adj[tmp.v][i].layer <= layer){//���С�ڸ����������ۼӽ��
					++inLayerCnt;
				}					
				visit[Adj[tmp.v][i].v] = 1;
			}
		}
	}
}

int main()
{
	int N, L;
	int ret = scanf("%d %d", &N, &L);
	int i, cnt, num;
	for (i = 0; i < N; ++i) {
		ret = scanf("%d", &cnt);
		for (int j = 0; j < cnt; ++j) {//��������
			ret = scanf("%d", &num);
			node tmp;
			tmp.v = i + 1;
			Adj[num].push_back(tmp);
		}
	}
	ret = scanf("%d", &cnt);
	for (i = 0; i < cnt; ++i) {
		ret = scanf("%d", &num);
		int res = 0;
		BFS(num, L, res);
		printf("%d\n", res);
	}
	return 0;
}